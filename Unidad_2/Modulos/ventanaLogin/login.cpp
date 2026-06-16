#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);

    // Agrego usuarios validados  (id, psw)
    users.insert("admin", "admin");
    users.insert("haedo", "utn");
    users.insert("bio", "prog");
}

login::~login()
{
    delete ui;
}

void login::on_btnIngresar_clicked()
{
    QString userLogin;
    QString pswLogin;

    /* Importo datos de QLineEdit */
    userLogin = ui->inUser->text();
    pswLogin = ui->inPsw->text();

    /* Validacion de datos de usuario */
    qDebug() << users;
    if(users.contains(userLogin)){  // Verifica existencia de usuario
        qDebug() << "Usuario existente";
        qDebug() << "USER: " << userLogin  << "  - existe?: " << users.contains(userLogin);
        qDebug() << "PSW: " << pswLogin  << "  - contrasenia real: " << users.key(userLogin);
        if(users.value(userLogin) == pswLogin){ // Busca contrasenia en usuario validado y verifica
            qDebug() << "Contraseña correcta";
            lastUser= userLogin;
            accept();  // Envia senial accept de QDialog
        }
        else{
            qDebug() << "Contraseña incorrecta";
            ui->inPsw->clear();  // Borro texto de QLineEdit para contrasenia
        }
    }
    else{
        qDebug() << "Usuario no existente";
        ui->inPsw->clear();  // Borro texto de QLineEdit para contrasenia
        ui->inUser->selectAll();  // Seleccion QLineEdit de usuario para indicar que debe cambiarse
    }
}

QString login::getInUser(){
    return lastUser;
}
