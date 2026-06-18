#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    /* Carga de usuarios validos */
    users.insert("admin", "admin");
    users.insert("utn", "haedo");
    users.insert("programacion", "bioingenieria");
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnIngresar_clicked()
{
    QString userLogin = ui->inUser->text();
    QString pswLogin = ui->inPsw->text();

    if(users.contains(userLogin)){
        if(users.value(userLogin) == pswLogin){
            userOk = userLogin;
            accept();
        }
        else{
            QMessageBox::critical(this, "Login", "Contrseña incorrecta");
            ui->inPsw->clear();
        }
    }
    else{
        QMessageBox::warning(this, "Login", "Usuario no existente");
        ui->inUser->selectAll();
    }
}

QString Login::getUserLogin(){
    return userOk;
}

