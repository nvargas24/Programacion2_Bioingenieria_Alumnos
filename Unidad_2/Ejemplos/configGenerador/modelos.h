#ifndef MODELOS_H
#define MODELOS_H

#include <QDialog>

namespace Ui {
class Modelos;
}

class Modelos : public QDialog
{
    Q_OBJECT

public:
    explicit Modelos(QWidget *parent = nullptr);
    ~Modelos();

    /* setters */
    void setListMarcas(QStringList);

    /* getters */
    QVector<QString> getModelo();

private slots:
    void on_btnAceptarG_clicked();

private:
    Ui::Modelos *ui;
};

#endif // MODELOS_H
