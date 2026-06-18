#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnIngresar_clicked()
{
    QString userLogin = ui->inUser->text();
    QString pswLogin = ui->inPsw->text();
}

