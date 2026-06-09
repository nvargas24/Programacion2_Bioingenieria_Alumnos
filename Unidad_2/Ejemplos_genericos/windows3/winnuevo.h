#ifndef WINNUEVO_H
#define WINNUEVO_H

#include <QDialog>
#include <QDebug>
namespace Ui {
class winNuevo;
}

class winNuevo : public QDialog
{
    Q_OBJECT

public:
    explicit winNuevo(QWidget *parent = nullptr);
    ~winNuevo();

    // getter que puede acceder mainwindow a win2
    QString getNombre();

private slots:
    void on_btnQuiero_clicked();

    void on_btnIgnorar_clicked();

private:
    Ui::winNuevo *ui;
};

#endif // WINNUEVO_H
