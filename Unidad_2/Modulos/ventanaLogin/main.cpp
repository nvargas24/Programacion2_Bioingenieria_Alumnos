#include "mainwindow.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login l;
    MainWindow w;

    if(l.exec() == QDialog::Accepted){ // Se ejecuta ventana QDialog
        w.setUser(l.getInUser()); // Getter de QDialog obtiene 'Usuario' que ingresa y Setter de QMainWindow lo carga
        w.show(); // Muestra QMainwindow
        return a.exec();
    }

    return 0;
}
