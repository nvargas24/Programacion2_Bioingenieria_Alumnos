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

    /* getters */

private slots:
    void on_btnModeloG_clicked();

    void on_btnParametrosG_clicked();

private:
    Ui::MainWindow *ui;
    Parametros* uiWinParametros;
    Modelos* uiWinModelos;
};
#endif // MAINWINDOW_H
