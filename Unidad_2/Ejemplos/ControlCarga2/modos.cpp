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

void Modos::on_pushButton_clicked()
{
    accept();
}

// getter
QString Modos::getModo(){
    QString seleccion;

    seleccion = ui->rbtnGroupModos->checkedButton()->text();
    qDebug() << "Selecciono: " << seleccion;

    return seleccion;
}

// setter
void Modos::setModo(QString mode){
    QList<QAbstractButton*> listRBtn;
    QAbstractButton* rbtn;

    listRBtn = ui->rbtnGroupModos->buttons();

    for(int i=0; i<listRBtn.size(); i++){
        rbtn = listRBtn[i];
        if(rbtn->text() == mode){
            rbtn->setChecked(true);
            break;
        }
    }


}
