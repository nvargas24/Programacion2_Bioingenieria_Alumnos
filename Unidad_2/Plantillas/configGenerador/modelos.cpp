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

