#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    //void on_verticalSlider_valueChanged(int value);
    void updatePlot();
private:
    Ui::MainWindow *ui;
    QTimer dataTimer;
    int row = 0;
};
#endif // MAINWINDOW_H
