#include "limites.h"
#include "ui_limites.h"

Limites::Limites(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Limites)
{
    ui->setupUi(this);
}

Limites::~Limites()
{
    delete ui;
}

void Limites::on_btnAceptar_clicked()
{
    accept();
}

// getter
QList<int> Limites::getLimites(){
    valueMin = ui->sboxMin->value();
    valueMax = ui->sboxMax->value();

    // opcional: limpio QSpinBox
    ui->sboxMin->clear();
    ui->sboxMax->clear();

    return {valueMin, valueMax};
}

// setter
void Limites::setLimites(QList<int> rango){
    ui->sboxMin->setValue(rango[0]);
    ui->sboxMax->setValue(rango[1]);
}
