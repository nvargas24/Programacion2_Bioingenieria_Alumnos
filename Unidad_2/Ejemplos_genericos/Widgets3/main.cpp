#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //qDebug() << QStyleFactory::keys();

    QFile archivo("../../../Estilos/win11black.css");

    if (archivo.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream lector(&archivo);
        QString estilo = lector.readAll();
        archivo.close();

        a.setStyleSheet(estilo);
    } else {
        qDebug() << "Error: No se pudo abrir el archivo CSS en la ruta especificada.";
    }

    w.show();

    return a.exec();
}
