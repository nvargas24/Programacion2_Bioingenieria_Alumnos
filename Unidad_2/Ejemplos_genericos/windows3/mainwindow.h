#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "winnuevo.h"
#include "winauxiliar.h"
#include "wincalibracion.h"
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

private slots:
    void on_btnNuevo_clicked();

    void on_btnControl_clicked();

    void on_btnCalibrar_clicked();

private:
    Ui::MainWindow *ui;
    winNuevo *win2; // puntero para ventana secundaria
    winAuxiliar *win3; // puntero para otra ventana auxiliar
    winCalibracion *win4;
};
#endif // MAINWINDOW_H
