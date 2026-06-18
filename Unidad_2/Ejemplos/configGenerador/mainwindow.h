#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "parametros.h"
#include "modelos.h"

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

    /* setters */
    void setUserLogin(QString);

    /* getters */

private slots:
    void on_btnModeloG_clicked();

    void on_btnParametrosG_clicked();

    void on_btnStatusG_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    Parametros* uiWinParametros;
    Modelos* uiWinModelos;

    /* Datos de ventanas secundarias*/
    QVector<QString> modeloSelect;
    QVector<int> paramSelect;
};
#endif // MAINWINDOW_H
