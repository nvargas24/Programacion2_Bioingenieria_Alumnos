#include "auxiliarb.h"
#include "ui_auxiliarb.h"

auxiliarB::auxiliarB(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::auxiliarB)
{
    ui->setupUi(this);
}

auxiliarB::~auxiliarB()
{
    delete ui;
}
