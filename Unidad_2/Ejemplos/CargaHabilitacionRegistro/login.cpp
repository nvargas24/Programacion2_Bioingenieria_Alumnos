#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    users.insert("admin", "admin");
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_btnAceptar_clicked()
{
    QString inUser;

    inUser = ui->inUsuario->text();
    qDebug()<<inUser;

    if(users.contains(inUser)){
        accept();
    }
    else{
        ui->inUsuario->clear();
        ui->inUsuario->setFocus();
    }

}

