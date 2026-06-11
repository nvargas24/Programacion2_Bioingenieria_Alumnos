#include "configvalue.h"
#include "ui_configvalue.h"

configValue::configValue(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::configValue)
{
    ui->setupUi(this);
}

configValue::~configValue()
{
    delete ui;
}
