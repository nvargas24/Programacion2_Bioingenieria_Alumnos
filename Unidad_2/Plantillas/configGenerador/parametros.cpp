#include "parametros.h"
#include "ui_parametros.h"

Parametros::Parametros(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Parametros)
{
    ui->setupUi(this);
}

Parametros::~Parametros()
{
    delete ui;
}

void Parametros::on_sliderTension_valueChanged(int value)
{
    ui->lcdTension->display(value);
}


void Parametros::on_sliderCorriente_valueChanged(int value)
{
    ui->lcdCorriente->display(value);
}


void Parametros::on_btnAceptarConfig_clicked()
{
    accept();
}

