#ifndef WINAUXILIAR_H
#define WINAUXILIAR_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class winAuxiliar;
}

class winAuxiliar : public QDialog
{
    Q_OBJECT

public:
    explicit winAuxiliar(QWidget *parent = nullptr);
    ~winAuxiliar();

    // setter para cargar en QList
    void setNombre(QString);

private:
    Ui::winAuxiliar *ui;
};

#endif // WINAUXILIAR_H
