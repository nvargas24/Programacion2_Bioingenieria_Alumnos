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
    void on_btn_conectar_clicked();
    void on_btn_actualizar_clicked();
    void on_btn_enviar_clicked();
    void recibirDatosSeriales();
    void manejarErrorSerial(QSerialPort::SerialPortError error);

private:
    void actualizarPuertos();
    void actualizarInterfazConexion(bool conectado);

    Ui::MainWindow *ui;
    QSerialPort m_serial;
};

#endif // MAINWINDOW_H
