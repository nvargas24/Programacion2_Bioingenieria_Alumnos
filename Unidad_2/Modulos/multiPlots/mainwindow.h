#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>

// Se incluye para poder utilizar punterors QCPBars y QCPGraph en .h, en .cpp no hubiese sido necesario
#include "../../Recursos/qcustom/qcustomplot.h"

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

    // Obtiene valores random para x e y, y la cantidad solicitada
    void valuesRandom(QVector<double>&, QVector<double>&, int);

    // Obtiene el valor maximo en el QVector
    double maxNumVector(QVector<double>&);

    // Seteo general para graficos segun datos x e y
    void configGraphs(QVector<double>&, QVector<double>&);

private slots:
    void on_btnDefault_clicked();

    void on_btnRandom_clicked();

    void on_btnClear_clicked();

private:
    /* Punteros para interactuar con Widgets*/
    Ui::MainWindow *ui;
    QCPBars* misBarras;
    QCPGraph* miLine;

    /* Variables para datos deafult*/
    QVector<double> xValuesD;
    QVector<double> yValuesD;
};
#endif // MAINWINDOW_H
