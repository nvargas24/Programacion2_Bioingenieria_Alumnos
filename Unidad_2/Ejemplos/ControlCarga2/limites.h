#ifndef LIMITES_H
#define LIMITES_H

#include <QDialog>

namespace Ui {
class Limites;
}

class Limites : public QDialog
{
    Q_OBJECT

public:
    explicit Limites(QWidget *parent = nullptr);
    ~Limites();

    // getters  ; opcional: podria obtener los valores por separado.
    QList<int> getLimites();

    // setters
    void setLimites(QList<int> rango);

private slots:
    void on_btnAceptar_clicked();

private:
    Ui::Limites *ui;
    int valueMin;
    int valueMax;
};

#endif // LIMITES_H
