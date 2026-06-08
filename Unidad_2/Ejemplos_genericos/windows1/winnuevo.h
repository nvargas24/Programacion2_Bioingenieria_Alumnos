#ifndef WINNUEVO_H
#define WINNUEVO_H

#include <QDialog>

namespace Ui {
class winNuevo;
}

class winNuevo : public QDialog
{
    Q_OBJECT

public:
    explicit winNuevo(QWidget *parent = nullptr);
    ~winNuevo();

private slots:
    void on_btnQuiero_clicked();

    void on_btnIgnorar_clicked();

private:
    Ui::winNuevo *ui;
};

#endif // WINNUEVO_H
