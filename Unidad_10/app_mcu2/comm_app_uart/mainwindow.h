#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQueue>
#include <QSerialPort>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_rojo_clicked();
    void on_btn_verde_clicked();
    void on_btn_azul_clicked();
    void recibirDatosSeriales();
    void manejarErrorSerial(QSerialPort::SerialPortError error);
    void manejarTimeoutRespuesta();

private:
    void conectarPuertoConfigurado();
    void enviarComando(char comando);
    void enviarSiguienteComando();
    void actualizarEstadoLED(char confirmacion);
    void actualizarInterfazConexion(bool conectado);
    void actualizarEstadoEnvio();

    Ui::MainWindow *ui;
    QSerialPort m_serial;
    QTimer m_responseTimer;
    QQueue<char> m_pendingCommands;
    char m_currentCommand = '\0';
    bool m_waitingForResponse = false;
    bool m_deviceReady = false;
};

#endif // MAINWINDOW_H
