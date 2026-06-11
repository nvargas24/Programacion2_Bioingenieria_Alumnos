#include "auxiliarc.h"
#include "ui_auxiliarc.h"

auxiliarC::auxiliarC(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::auxiliarC)
{
    ui->setupUi(this);
}

auxiliarC::~auxiliarC()
{
    delete ui;
}
