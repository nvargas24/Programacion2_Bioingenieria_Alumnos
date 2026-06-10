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
