#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QList>

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

    void setSaldo(int); // Actualiza atributo privado saldo

    bool validacionSaldo(int); // Verifica si el monto es valido
private slots:
    void on_btnVerSaldo_pressed();

    void on_btnVerSaldo_released();

    void on_btnDepositar_clicked();

private:
    Ui::MainWindow *ui;
    int saldoActual; // Saldo en cuenta
    QList<QString> movimientos; // Mensajes posibles a mostrar en QListWidget
};
#endif // MAINWINDOW_H
