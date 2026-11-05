#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPortInfo>
#include <QTextCursor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&m_serial, &QSerialPort::errorOccurred,
            this, &MainWindow::manejarErrorSerial);
    connect(&m_serial, &QSerialPort::readyRead,
            this, &MainWindow::recibirDatosSeriales);
    connect(ui->lineEdit_mensaje, &QLineEdit::returnPressed,
            this, &MainWindow::on_btn_enviar_clicked);

    actualizarPuertos();
    actualizarInterfazConexion(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_conectar_clicked()
{
    if (m_serial.isOpen()) {
        m_serial.close();
        actualizarInterfazConexion(false);
        ui->lbl_conexion->setText(tr("Desconectado."));
        return;
    }

    const QString nombrePuerto = ui->cb_puertos->currentData().toString();
    if (nombrePuerto.isEmpty()) {
        ui->lbl_conexion->setText(tr("Selecciona un puerto serie."));
        return;
    }

    m_serial.setPortName(nombrePuerto);
    m_serial.setBaudRate(QSerialPort::Baud115200);
    m_serial.setDataBits(QSerialPort::Data8);
    m_serial.setParity(QSerialPort::NoParity);
    m_serial.setStopBits(QSerialPort::OneStop);
    m_serial.setFlowControl(QSerialPort::NoFlowControl);

    if (!m_serial.open(QIODevice::ReadWrite)) {
        ui->lbl_conexion->setText(
            tr("No se pudo conectar: %1").arg(m_serial.errorString()));
        return;
    }

    actualizarInterfazConexion(true);
    ui->lbl_conexion->setText(
        tr("Conectado a %1.").arg(nombrePuerto));
}

void MainWindow::on_btn_actualizar_clicked()
{
    actualizarPuertos();
}

void MainWindow::on_btn_enviar_clicked()
{
    const QByteArray mensaje = ui->lineEdit_mensaje->text().toUtf8();
    if (mensaje.isEmpty())
        return;

    const qint64 bytesEnviados = m_serial.write(mensaje);
    if (bytesEnviados != mensaje.size()) {
        ui->lbl_conexion->setText(
            tr("No se pudo enviar el mensaje: %1").arg(m_serial.errorString()));
        return;
    }

    ui->lineEdit_mensaje->clear();
}

void MainWindow::recibirDatosSeriales()
{
    QString datos = QString::fromUtf8(m_serial.readAll());
    datos.replace(QStringLiteral("\r\n"), QStringLiteral("\n"));
    datos.replace(QLatin1Char('\r'), QLatin1Char('\n'));

    QTextCursor cursor = ui->textEdit_recibido->textCursor();
    cursor.movePosition(QTextCursor::End);
    cursor.insertText(datos);
    ui->textEdit_recibido->setTextCursor(cursor);
    ui->textEdit_recibido->ensureCursorVisible();
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
        ui->lbl_conexion->setText(tr("Se perdió la conexión: %1").arg(mensaje));
        return;
    }

    ui->lbl_conexion->setText(tr("Error del puerto serie: %1").arg(mensaje));
}

void MainWindow::actualizarPuertos()
{
    const QString puertoSeleccionado = ui->cb_puertos->currentData().toString();
    ui->cb_puertos->clear();

    const QList<QSerialPortInfo> puertos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &puerto : puertos) {
        const QString nombre = puerto.portName();
        const QString descripcion = puerto.description().isEmpty()
                                        ? nombre
                                        : QStringLiteral("%1 (%2)").arg(nombre, puerto.description());
        ui->cb_puertos->addItem(descripcion, nombre);
    }

    const int indice = ui->cb_puertos->findData(puertoSeleccionado);
    if (indice >= 0)
        ui->cb_puertos->setCurrentIndex(indice);

    if (puertos.isEmpty())
        ui->lbl_conexion->setText(tr("No se encontraron puertos serie."));
    else
        ui->lbl_conexion->setText(tr("Selecciona un puerto y presiona Conectar."));
}

void MainWindow::actualizarInterfazConexion(bool conectado)
{
    ui->cb_puertos->setEnabled(!conectado);
    ui->btn_actualizar->setEnabled(!conectado);
    ui->btn_conectar->setText(conectado ? tr("Desconectar") : tr("Conectar"));
    ui->textEdit_recibido->setEnabled(conectado);
    ui->lineEdit_mensaje->setEnabled(conectado);
    ui->btn_enviar->setEnabled(conectado);

    if (!conectado) {
        ui->textEdit_recibido->clear();
        ui->lineEdit_mensaje->clear();
    }
}
