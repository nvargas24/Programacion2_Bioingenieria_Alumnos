#include "modelos.h"
#include "ui_modelos.h"

Modelos::Modelos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Modelos)
{
    ui->setupUi(this);
}

Modelos::~Modelos()
{
    delete ui;
}

void Modelos::on_btnAceptarG_clicked()
{
    accept();
}

void Modelos::setListMarcas(QStringList list){
    ui->cboxMarcaG->clear();
    ui->cboxMarcaG->addItems(list);
}

QVector<QString> Modelos::getModelo(){
    QString marca, anio;

    marca = ui->cboxMarcaG->currentText();
    anio = ui->yearG->text();

    return {marca, anio};
}
