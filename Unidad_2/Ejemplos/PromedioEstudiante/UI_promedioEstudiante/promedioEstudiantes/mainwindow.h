#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct Curso{
    QString apellido;
    float promedio;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString statusEstudiante();

private slots:
    void on_btnCalcular_clicked();

private:
    Ui::MainWindow *ui;
    Curso estudiante;
    Curso* ptr;
};
#endif // MAINWINDOW_H
