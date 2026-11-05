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
    void on_btn_encender_clicked();
    void on_btn_apagar_clicked();
    void on_btn_invertir_clicked();
    void on_btn_consultar_clicked();
    void on_btn_ayuda_clicked();
    void on_btn_probar_clicked();
    void recibirDatosSeriales();
    void manejarErrorSerial(QSerialPort::SerialPortError error);
    void manejarTimeoutRespuesta();

private:
    void conectarPuertoConfigurado();
    void enviarComando(char comando);
    void enviarSiguienteComando();
    void procesarRespuesta(const QByteArray &respuesta);
    void actualizarEstadoLED(bool encendido);
    void actualizarInterfazConexion(bool conectado);
    void actualizarEstadoEnvio();

    Ui::MainWindow *ui;
    QSerialPort m_serial;
    QTimer m_responseTimer;
    QByteArray m_responseBuffer;
    QQueue<char> m_pendingCommands;
    char m_currentCommand = '\0';
    bool m_waitingForResponse = false;
    bool m_deviceReady = false;
};

#endif // MAINWINDOW_H
