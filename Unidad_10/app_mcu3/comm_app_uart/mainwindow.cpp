#include "mainwindow.h"
#include "ui_mainwindow.h"

#define UART_PORT_NAME "COM7"
#define UART_BAUD_RATE 115200

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&m_serial, &QSerialPort::errorOccurred,
            this, &MainWindow::manejarErrorSerial);

    actualizarInterfazConexion(false);
    actualizarEstadoLED('0');
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

    actualizarInterfazConexion(true);
    ui->lbl_conexion->setText(
        tr("Conectado a %1 a %2 baudios.")
            .arg(QStringLiteral(UART_PORT_NAME))
            .arg(UART_BAUD_RATE));
    ui->lbl_conexion->setStyleSheet(QStringLiteral("color: green;"));
}

void MainWindow::on_btn_rojo_clicked()
{
    if (enviarComando('R'))
        actualizarEstadoLED('R');
}

void MainWindow::on_btn_verde_clicked()
{
    if (enviarComando('G'))
        actualizarEstadoLED('G');
}

void MainWindow::on_btn_azul_clicked()
{
    if (enviarComando('B'))
        actualizarEstadoLED('B');
}

void MainWindow::manejarErrorSerial(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::NoError)
        return;

    const QString mensaje = m_serial.errorString();
    if (error == QSerialPort::ResourceError) {
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

bool MainWindow::enviarComando(char comando)
{
    if (!m_serial.isOpen())
        return false;

    if (m_serial.write(&comando, 1) != 1) {
        ui->lbl_conexion->setText(
            tr("No se pudo enviar el comando: %1").arg(m_serial.errorString()));
        ui->lbl_conexion->setStyleSheet(QStringLiteral("color: red;"));
        return false;
    }

    return true;
}

void MainWindow::actualizarEstadoLED(char comando)
{
    QString colorCss = QStringLiteral("#9e9e9e");
    switch (comando) {
    case 'R':
        colorCss = QStringLiteral("#f44336");
        break;
    case 'G':
        colorCss = QStringLiteral("#4caf50");
        break;
    case 'B':
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
}
