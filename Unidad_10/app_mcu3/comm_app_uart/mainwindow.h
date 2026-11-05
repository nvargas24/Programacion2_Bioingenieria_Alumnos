#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

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
    void manejarErrorSerial(QSerialPort::SerialPortError error);

private:
    void conectarPuertoConfigurado();
    bool enviarComando(char comando);
    void actualizarEstadoLED(char comando);
    void actualizarInterfazConexion(bool conectado);

    Ui::MainWindow *ui;
    QSerialPort m_serial;
};

#endif // MAINWINDOW_H
