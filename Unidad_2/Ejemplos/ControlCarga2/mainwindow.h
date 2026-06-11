#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modos.h"
#include "limites.h"

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
    void on_sliderCarga1_valueChanged(int value);

    void on_sliderCarga2_valueChanged(int value);

    void on_dialCarga1_valueChanged(int value);

    void on_dialCarga2_valueChanged(int value);

    void on_sboxCarga1_valueChanged(int value);

    void on_sboxCarga2_valueChanged(int value);

    void on_btnLimites_clicked();

    void on_btnModos_clicked();

    void on_btnColor_pressed();

    void on_btnColor_released();

    void on_cboxSlider_toggled(bool checked);

    void on_cboxDial_toggled(bool checked);

    void on_cboxSpin_toggled(bool checked);

private:
    Ui::MainWindow *ui;

    Modos* uiModos;
    QString modepbar;

    Limites* uiLimites;
    QList<int> rangoLimites;

    double per;
    int maxGeneral;
    int valueCarga1;
    int valueCarga2;

    void setNewValuePBar();
    void setNewLim();

};
#endif // MAINWINDOW_H
