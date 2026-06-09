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

// Implementacion  de getter
QString winNuevo::getNombre(){
    QString nombre = ui->inNombre->text(); //  Extraigo texto de QLineEdit
    ui->inNombre->clear(); // limpio texto en QLineEdit

    return nombre;
}

// Slots de ventana secundaria - responde con señales basicas a mainwindow
void winNuevo::on_btnQuiero_clicked()
{
    qDebug() << "[WIN2] Selecciono 'Quiero'";
    accept();
}

void winNuevo::on_btnIgnorar_clicked()
{
    qDebug() << "[WIN2] Selecciono 'Ignorar'";
    reject();
}

