#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>

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
    double maxNumVector(QVector<double>&);
    void configGraphPolar(QList<double>&);
private slots:


    void on_sliderNike_valueChanged(int value);

    void on_sliderAdidas_valueChanged(int value);

    void on_sliderPuma_valueChanged(int value);

    void on_sliderReebok_valueChanged(int value);

    void on_sliderTopper_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QLineSeries* series1;
    QPolarChart* radar;
    QCategoryAxis* etiquetaAngular;
    QValueAxis *ejeRadial;

    QList<double> values; // nike, adidas, puma, reekboot, topper
    QVector<QString> listLabel;
};
#endif // MAINWINDOW_H
