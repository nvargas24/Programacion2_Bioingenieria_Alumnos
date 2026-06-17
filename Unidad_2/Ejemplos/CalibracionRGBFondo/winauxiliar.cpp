#include "winauxiliar.h"
#include "ui_winauxiliar.h"

winAuxiliar::winAuxiliar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::winAuxiliar)
{
    ui->setupUi(this);
}

winAuxiliar::~winAuxiliar()
{
    delete ui;
}

void winAuxiliar::setNombre(QString nombre){
    ui->listNombres->addItem(nombre);
    qDebug() << "[win3] Carga texto en QList";
}
