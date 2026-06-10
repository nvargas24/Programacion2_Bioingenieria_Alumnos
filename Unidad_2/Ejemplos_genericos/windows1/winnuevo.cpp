#include "winnuevo.h"
#include "ui_winnuevo.h"

winNuevo::winNuevo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::winNuevo)
{    
    ui->setupUi(this);
}

winNuevo::~winNuevo()
{
    delete ui;
}

// Slots de ventana secundaria - responde con señales basicas a mainwindow
void winNuevo::on_btnQuiero_clicked()
{
    accept();
}

void winNuevo::on_btnIgnorar_clicked()
{
    reject();
}

