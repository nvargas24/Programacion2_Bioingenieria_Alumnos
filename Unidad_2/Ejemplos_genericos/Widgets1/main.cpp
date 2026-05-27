#include "mainwindow.h"
#include <QObject>
#include <QApplication>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QMainWindow>
#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(800,900);

    QLabel Label1 ("Texto de ejemplo", &w);
    Label1.setGeometry(0,100,120,120);
    Label1.show();

    QTextEdit texto1 ("Texto de ejemplo",&w);
    texto1.setGeometry(100,100,50,200);


    QComboBox *comboBox = new QComboBox(&w);
    comboBox->addItem("Opción 1");
    comboBox->addItem("Opción 2");
    comboBox->addItem("Opción 3");
    comboBox->setGeometry(200,100,200,50);
    comboBox-> show();

    QCheckBox *checkBox = new QCheckBox("Click para chequear",&w);
    checkBox->setGeometry(450,100,200,50);
    checkBox->show();
    checkBox->setTristate();


    QRadioButton *radio1 = new QRadioButton("Opción A", &w);
    radio1->setGeometry(50, 300, 100, 30);
    QRadioButton radio2 = QRadioButton("Opción B", &w);
    radio2.setGeometry(50,350,100,30);
    // QRadioButton *radio2 = new QRadioButton("Opción B", &w);
    // radio2->setGeometry(50, 340, 100, 30);

    // QRadioButton *radio3 = new QRadioButton("Opción C", &w);
    // radio3->setGeometry(50, 390, 100, 30);


    // QButtonGroup *grupoBotones = new QButtonGroup(&w);
    // grupoBotones->addButton(radio1, 1);
    // grupoBotones->addButton(radio2, 2);
    // grupoBotones->addButton(radio3, 3);

    // radio1->show();
    // radio2->show();
    // radio3->show();

    QPushButton boton1 ("Boton 1");
    boton1.show();

    QPushButton *boton2 = new QPushButton("Presionar", &w);
    boton2 -> setGeometry(50,450,80,30);


    QMessageBox::information(&w, "Título", "Este es un mensaje informativo.");
    QMessageBox::warning(&w, "Advertencia", "Esto es una advertencia.");
    QMessageBox::critical(&w, "Error", "Ha ocurrido un error.");
    QMessageBox::about(&w, "Acerca de", "Otro tipo de información");



    w.show();
    return a.exec();
}
