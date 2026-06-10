#ifndef WINCALIBRACION_H
#define WINCALIBRACION_H

#include <QDialog>
#include <QList>

namespace Ui {
class winCalibracion;
}

class winCalibracion : public QDialog
{
    Q_OBJECT

public:
    explicit winCalibracion(QWidget *parent = nullptr);
    ~winCalibracion();

    // getter para obtener calibracion de color RGB
    QList<int> getRGB();

private slots:
    void on_vsliderR_valueChanged(int value);

    void on_dialR_valueChanged(int value);

    void on_vsliderG_valueChanged(int value);

    void on_dialG_valueChanged(int value);

    void on_vsliderB_valueChanged(int value);

    void on_dialB_valueChanged(int value);

    void on_btnAceptar_clicked();

private:
    Ui::winCalibracion *ui;
    QList<int> listRGB;  // (R, G, B)
};

#endif // WINCALIBRACION_H
