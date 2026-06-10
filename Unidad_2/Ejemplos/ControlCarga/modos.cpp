#include "modos.h"
#include "ui_modos.h"

Modos::Modos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Modos)
{
    ui->setupUi(this);
}

Modos::~Modos()
{
    delete ui;
}
