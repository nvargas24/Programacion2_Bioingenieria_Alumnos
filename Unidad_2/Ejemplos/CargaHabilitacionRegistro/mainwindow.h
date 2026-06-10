#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_spinNum_valueChanged(int arg1);
    void on_sliderCarga_valueChanged(int value);

    void on_grbtnEnabled_idClicked(int id);

    void on_checkColores_toggled(bool checked);

    void on_checkAnimales_toggled(bool checked);

    void on_checkCosas_toggled(bool checked);

    void clearCboxOpciones(QStringList list);
    void on_cboxOpciones_textActivated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QStringList listColores;
    QStringList listAnimales;
    QStringList listCosas;
    QStringList listRegistros;
};
#endif // MAINWINDOW_H
