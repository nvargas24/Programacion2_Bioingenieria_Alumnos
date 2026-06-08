#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnIngresar_clicked()
{
    QString nombre;
    int edad;
    QString textoMostrar;

    nombre = ui->inNombre->text();
    edad = ui->inEdad->text().toInt();

    qDebug()<<"Ingreso nombre: "<<nombre;
    qDebug()<<"Ingreso edad: "<<edad;

    textoMostrar = "Nombre: "+nombre+ "-Edad: "+ QString::number(edad);

    ui->labelIngresados->setText(textoMostrar);

}

