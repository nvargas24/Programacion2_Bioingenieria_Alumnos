#include "mainwindow.h"

#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Login l;

    if(l.exec() == QDialog::Accepted){
        w.setUserLogin(l.getUserLogin());
        w.show();
        return a.exec();
    }

    return 0;
}
