#ifndef PARAMETROS_H
#define PARAMETROS_H

#include <QDialog>

namespace Ui {
class Parametros;
}

class Parametros : public QDialog
{
    Q_OBJECT

public:
    explicit Parametros(QWidget *parent = nullptr);
    ~Parametros();

    /* setters */

    /* getters */

private slots:
    void on_sliderTension_valueChanged(int value);

    void on_sliderCorriente_valueChanged(int value);

    void on_btnAceptarConfig_clicked();

private:
    Ui::Parametros *ui;
};

#endif // PARAMETROS_H
