#include "wincalibracion.h"
#include "ui_wincalibracion.h"

winCalibracion::winCalibracion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::winCalibracion)
{
    ui->setupUi(this);
}

winCalibracion::~winCalibracion()
{
    delete ui;
}

/******  Calibracion Rojo  ******/
void winCalibracion::on_vsliderR_valueChanged(int value)
{
    ui->lcdValueR->display(value);
    ui->dialR->setValue(value);
}

void winCalibracion::on_dialR_valueChanged(int value)
{
    ui->vsliderR->setValue(value);
    ui->dialR->setValue(value);
}

/******  Calibracion Verde  ******/
void winCalibracion::on_vsliderG_valueChanged(int value)
{
    ui->lcdValueG->display(value);
    ui->dialG->setValue(value);
}

void winCalibracion::on_dialG_valueChanged(int value)
{
    ui->vsliderG->setValue(value);
    ui->dialG->setValue(value);
}

/******  Calibracion Azul  ******/
void winCalibracion::on_vsliderB_valueChanged(int value)
{
    ui->lcdValueB->display(value);
    ui->dialB->setValue(value);
}

void winCalibracion::on_dialB_valueChanged(int value)
{
    ui->vsliderB->setValue(value);
    ui->dialB->setValue(value);
}

void winCalibracion::on_btnAceptar_clicked()
{
    accept();
}

QList<int> winCalibracion::getRGB(){
    listRGB.clear(); // Necesario para evitar que se agreguen mas de 3 elemento a la QList

    listRGB.append(ui->lcdValueR->value());
    listRGB.append(ui->lcdValueG->value());
    listRGB.append(ui->lcdValueB->value());
    qDebug()<< "[WIN4] Exporta RGB: " << listRGB;

    return listRGB;
}

