#include "configpersonal.h"
#include "ui_configpersonal.h"

configPersonal::configPersonal(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::configPersonal)
{
    ui->setupUi(this);
}

configPersonal::~configPersonal()
{
    delete ui;
}
