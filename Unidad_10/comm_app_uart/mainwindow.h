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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool conectarLPC(const QString &nombrePuerto, qint32 baudRate = QSerialPort::Baud115200);
    void desconectarLPC();
    void enviarComandoLED(char comando);

private:
    Ui::MainWindow *ui;
    QSerialPort *m_serial;
};
#endif // MAINWINDOW_H
