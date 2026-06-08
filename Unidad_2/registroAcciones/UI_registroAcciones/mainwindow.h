#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QString>
#include <QDebug>

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
    void on_btnIngresar_clicked();

    void on_btnTodo_clicked();

    void on_btnUltimo_clicked();

    void on_inAcciones_returnPressed();

private:
    Ui::MainWindow *ui;
    QStack<QString> acciones;
};
#endif // MAINWINDOW_H
