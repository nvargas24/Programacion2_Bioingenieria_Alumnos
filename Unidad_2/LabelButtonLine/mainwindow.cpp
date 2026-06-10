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

    /* Extrae datos de widgets */
    nombre = ui->inNombre->text();
    edad = ui->inEdad->text().toInt();

    /* Test por terminal */
    qDebug()<<"Ingreso nombre: "<<nombre;
    qDebug()<<"Ingreso edad: "<<edad;

    /* Carga a widget */
    textoMostrar = "Nombre: "+nombre+ "  -   Edad: " + QString::number(edad) + " años"; // Defino QString a mostrar
    ui->labelIngresados->setText(textoMostrar); // Cargo QString a QLabel

    /* Limpieza de campos */
    ui->inNombre->clear();
    ui->inEdad->clear();
}

