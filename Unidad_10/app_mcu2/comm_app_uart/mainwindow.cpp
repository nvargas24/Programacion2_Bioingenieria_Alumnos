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
    actualizarEstadoLED('\0');
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

    m_deviceReady = false;
    actualizarInterfazConexion(true);
    ui->lbl_conexion->setText(
        tr("Puerto %1 abierto; sincronizando el LED...")
            .arg(QStringLiteral(UART_PORT_NAME)));
    ui->lbl_conexion->setStyleSheet(QString());

    enviarComando('0');
}

void MainWindow::on_btn_rojo_clicked()
{
    enviarComando('R');
}

void MainWindow::on_btn_verde_clicked()
{
    enviarComando('G');
}

void MainWindow::on_btn_azul_clicked()
{
    enviarComando('B');
}

void MainWindow::recibirDatosSeriales()
{
    const QByteArray datos = m_serial.readAll();

    char confirmacionEsperada = '\0';
    if (m_waitingForResponse) {
        switch (m_currentCommand) {
        case '0':
            confirmacionEsperada = '0';
            break;
        case 'R':
            confirmacionEsperada = '1';
            break;
        case 'G':
            confirmacionEsperada = '2';
            break;
        case 'B':
            confirmacionEsperada = '3';
            break;
        default:
            break;
        }
    }

    if (confirmacionEsperada != '\0' && datos.contains(confirmacionEsperada)) {
        actualizarEstadoLED(confirmacionEsperada);
        if (!m_deviceReady && m_currentCommand == '0') {
            m_deviceReady = true;
            ui->lbl_conexion->setText(
                tr("Conectado a %1 a %2 baudios.")
                    .arg(QStringLiteral(UART_PORT_NAME))
                    .arg(UART_BAUD_RATE));
            ui->lbl_conexion->setStyleSheet(QStringLiteral("color: green;"));
        }
        m_responseTimer.stop();
        m_waitingForResponse = false;
        m_currentCommand = '\0';
        actualizarEstadoEnvio();
        enviarSiguienteComando();
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

void MainWindow::actualizarEstadoLED(char confirmacion)
{
    QString colorCss = QStringLiteral("#f5f5f5");
    switch (confirmacion) {
    case '0':
        colorCss = QStringLiteral("#9e9e9e");
        break;
    case '1':
        colorCss = QStringLiteral("#f44336");
        break;
    case '2':
        colorCss = QStringLiteral("#4caf50");
        break;
    case '3':
        colorCss = QStringLiteral("#2196f3");
        break;
    default:
        break;
    }

    ui->lbl_led->setStyleSheet(
        QStringLiteral("QLabel { background-color: %1; border-radius: 30px; "
                       "border: 2px solid black; }").arg(colorCss));
}

void MainWindow::actualizarInterfazConexion(bool conectado)
{
    ui->btn_rojo->setEnabled(conectado);
    ui->btn_verde->setEnabled(conectado);
    ui->btn_azul->setEnabled(conectado);
    actualizarEstadoEnvio();

    if (!conectado) {
        m_deviceReady = false;
    }
}

void MainWindow::actualizarEstadoEnvio()
{
    const bool puedeEnviar = m_serial.isOpen() && m_deviceReady && !m_waitingForResponse;
    ui->btn_rojo->setEnabled(puedeEnviar);
    ui->btn_verde->setEnabled(puedeEnviar);
    ui->btn_azul->setEnabled(puedeEnviar);
}
