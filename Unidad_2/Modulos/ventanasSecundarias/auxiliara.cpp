#include "auxiliara.h"
#include "ui_auxiliara.h"

auxiliarA::auxiliarA(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::auxiliarA)
{
    ui->setupUi(this);
}

auxiliarA::~auxiliarA()
{
    delete ui;
}
