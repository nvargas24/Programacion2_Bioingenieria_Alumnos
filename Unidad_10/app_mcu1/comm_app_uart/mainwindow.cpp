#include "mainwindow.h"
#include "ui_mainwindow.h"

#define UART_PORT_NAME "COM7"
#define UART_BAUD_RATE 115200

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_responseTimer.setSingleShot(true);
    m_responseTimer.setInterval(2000);

    connect(&m_serial, &QSerialPort::errorOccurred,
            this, &MainWindow::manejarErrorSerial);
    connect(&m_serial, &QSerialPort::readyRead,
            this, &MainWindow::recibirDatosSeriales);
    connect(&m_responseTimer, &QTimer::timeout,
            this, &MainWindow::manejarTimeoutRespuesta);

    actualizarInterfazConexion(false);
    actualizarEstadoLED(false);
    //ui->lbl_mensaje_uart->setText(tr("Presiona un botón para recibir una respuesta."));
    conectarPuertoConfigurado();
}

MainWindow::~MainWindow()
{
    if (m_serial.isOpen())
        m_serial.close();

    delete ui;
}

void MainWindow::conectarPuertoConfigurado()
{
    m_serial.setPortName(QStringLiteral(UART_PORT_NAME));
    m_serial.setBaudRate(UART_BAUD_RATE);
    m_serial.setDataBits(QSerialPort::Data8);
    m_serial.setParity(QSerialPort::NoParity);
    m_serial.setStopBits(QSerialPort::OneStop);
    m_serial.setFlowControl(QSerialPort::NoFlowControl);

    if (!m_serial.open(QIODevice::ReadWrite)) {
        ui->lbl_conexion->setText(
            tr("No se pudo conectar a %1: %2")
                .arg(QStringLiteral(UART_PORT_NAME), m_serial.errorString()));
        ui->lbl_conexion->setStyleSheet(QStringLiteral("color: red;"));
        return;
    }

    m_responseBuffer.clear();
    m_deviceReady = false;
    actualizarInterfazConexion(true);
    ui->lbl_conexion->setText(
        tr("Puerto %1 abierto; verificando el LPC845...")
            .arg(QStringLiteral(UART_PORT_NAME)));
    ui->lbl_conexion->setStyleSheet(QString());

    enviarComando('?');

}

void MainWindow::on_btn_encender_clicked()
{
    enviarComando('1');
}

void MainWindow::on_btn_apagar_clicked()
{
    enviarComando('0');
}

void MainWindow::on_btn_invertir_clicked()
{
    enviarComando('t');
}

void MainWindow::recibirDatosSeriales()
{
    m_responseBuffer.append(m_serial.readAll());
    const QByteArray prompt("> ");
    int promptIndex = m_responseBuffer.indexOf(prompt);

    while (promptIndex >= 0) {
        const QByteArray respuesta = m_responseBuffer.left(promptIndex);
        m_responseBuffer.remove(0, promptIndex + prompt.size());
        procesarRespuesta(respuesta);
        promptIndex = m_responseBuffer.indexOf(prompt);
    }

    if (m_responseBuffer.size() > 1024) {
        const QByteArray datosAntiguos = m_responseBuffer.left(m_responseBuffer.size() - 1024);
        m_responseBuffer.remove(0, datosAntiguos.size());
        procesarRespuesta(datosAntiguos);
    }
}

void MainWindow::manejarErrorSerial(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::NoError)
        return;

    const QString mensaje = m_serial.errorString();
    if (error == QSerialPort::ResourceError) {
        m_responseTimer.stop();
        m_waitingForResponse = false;
        m_currentCommand = '\0';
        m_pendingCommands.clear();

        if (m_serial.isOpen())
            m_serial.close();

        actualizarInterfazConexion(false);
        ui->lbl_conexion->setText(tr("Conexión perdida: %1").arg(mensaje));
        ui->lbl_conexion->setStyleSheet(QStringLiteral("color: red;"));
        return;
    }

    ui->lbl_conexion->setText(tr("Error del puerto serie: %1").arg(mensaje));
    ui->lbl_conexion->setStyleSheet(QStringLiteral("color: red;"));
}

void MainWindow::manejarTimeoutRespuesta()
{
    m_waitingForResponse = false;
    m_currentCommand = '\0';
    m_pendingCommands.clear();
    actualizarEstadoEnvio();
    if (!m_deviceReady) {
        ui->lbl_conexion->setText(
            tr("No se detectó el LPC845 en %1. Los controles siguen bloqueados.")
                .arg(QStringLiteral(UART_PORT_NAME)));
    } else {
        ui->lbl_conexion->setText(tr("No se recibió respuesta del LPC845."));
    }
    ui->lbl_conexion->setStyleSheet(QStringLiteral("color: red;"));
}

void MainWindow::enviarComando(char comando)
{
    if (!m_serial.isOpen() || m_waitingForResponse)
        return;

    m_responseBuffer.clear();
    m_pendingCommands.enqueue(comando);
    enviarSiguienteComando();
}

void MainWindow::enviarSiguienteComando()
{
    if (!m_serial.isOpen() || m_waitingForResponse || m_pendingCommands.isEmpty())
        return;

    m_currentCommand = m_pendingCommands.dequeue();
    m_waitingForResponse = true;
    actualizarEstadoEnvio();

    if (m_serial.write(&m_currentCommand, 1) != 1) {
        m_waitingForResponse = false;
        m_currentCommand = '\0';
        m_pendingCommands.clear();
        actualizarEstadoEnvio();
        ui->lbl_conexion->setText(
            tr("No se pudo enviar el comando: %1").arg(m_serial.errorString()));
        ui->lbl_conexion->setStyleSheet(QStringLiteral("color: red;"));
        return;
    }

    m_responseTimer.start();
}

void MainWindow::procesarRespuesta(const QByteArray &respuesta)
{
    QString texto = QString::fromUtf8(respuesta);
    texto.replace(QStringLiteral("\r\n"), QStringLiteral("\n"));
    texto.replace(QLatin1Char('\r'), QLatin1Char('\n'));
    const bool esVerificacionInicial =
        !m_deviceReady && m_currentCommand == '?' &&
        texto.contains(QStringLiteral("Comandos:"));

    bool respuestaValida = false;
    if (texto.contains(QStringLiteral("LED azul encendido.")) ||
        texto.contains(QStringLiteral("LED azul: encendido."))) {
        actualizarEstadoLED(true);
        respuestaValida = true;
    } else if (texto.contains(QStringLiteral("LED azul apagado.")) ||
               texto.contains(QStringLiteral("LED azul: apagado."))) {
        actualizarEstadoLED(false);
        respuestaValida = true;
    } else if (texto.contains(QStringLiteral("LED azul invertido."))) {
        // El firmware no indica el estado final al invertir; consultar después.
        m_pendingCommands.enqueue('s');
        respuestaValida = true;
    } else if (texto.contains(QStringLiteral("Comandos:")) ||
               texto.contains(QStringLiteral("pong")) ||
               texto.contains(QStringLiteral("Tecla no reconocida."))) {
        respuestaValida = true;
    }

    if (m_waitingForResponse && respuestaValida) {
        if (!m_deviceReady && m_currentCommand == '?' &&
            texto.contains(QStringLiteral("Comandos:"))) {
            m_deviceReady = true;
            ui->lbl_conexion->setText(
                tr("Conectado a %1 a %2 baudios.")
                    .arg(QStringLiteral(UART_PORT_NAME))
                    .arg(UART_BAUD_RATE));
            ui->lbl_conexion->setStyleSheet(QStringLiteral("color: green;"));
        }

        QStringList lineas = texto.split(QLatin1Char('\n'), Qt::SkipEmptyParts);
        if (!lineas.isEmpty() &&
            lineas.first().trimmed() == QChar::fromLatin1(m_currentCommand)) {
            lineas.removeFirst();
        }

        const QString mensaje = lineas.join(QLatin1Char('\n')).trimmed();
        if (!esVerificacionInicial && !mensaje.isEmpty())
            ui->lbl_mensaje_uart->setText(mensaje);

        m_responseTimer.stop();
        m_waitingForResponse = false;
        m_currentCommand = '\0';
        actualizarEstadoEnvio();
        enviarSiguienteComando();
    }
}

void MainWindow::actualizarEstadoLED(bool encendido)
{
    const QString color = encendido ? QStringLiteral("#2196f3")
                                    : QStringLiteral("#f5f5f5");
    ui->lbl_led->setStyleSheet(
        QStringLiteral("QLabel { background-color: %1; border-radius: 30px; "
                       "border: 2px solid black; }").arg(color));
}

void MainWindow::actualizarInterfazConexion(bool conectado)
{
    ui->btn_encender->setEnabled(conectado);
    ui->btn_apagar->setEnabled(conectado);
    ui->btn_invertir->setEnabled(conectado);
    actualizarEstadoEnvio();

    if (!conectado) {
        m_deviceReady = false;
        //ui->lbl_mensaje_uart->setText(tr("Presiona un botón para recibir una respuesta."));
    }
}

void MainWindow::actualizarEstadoEnvio()
{
    const bool puedeEnviar = m_serial.isOpen() && m_deviceReady && !m_waitingForResponse;
    ui->btn_encender->setEnabled(puedeEnviar);
    ui->btn_apagar->setEnabled(puedeEnviar);
    ui->btn_invertir->setEnabled(puedeEnviar);
}
