#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
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

    void valuesRandom(QVector<double>&, QVector<double>&, int);
private:
    Ui::MainWindow *ui;
    QVector<double> xValues;
    QVector<double> yValues;
};
#endif // MAINWINDOW_H
