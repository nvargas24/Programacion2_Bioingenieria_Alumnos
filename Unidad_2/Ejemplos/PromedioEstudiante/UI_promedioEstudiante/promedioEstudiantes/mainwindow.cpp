#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), ptr(&estudiante)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCalcular_clicked()
{
    ptr->apellido = ui->inApellido->text();
    ptr->promedio = (ui->sboxNota1->value() + ui->sboxNota2->value()) / 2;

    ui->labelPromedio->setText("Promedio: "+ QString::number(ptr->promedio) + " - Estado: "+ statusEstudiante());
}

QString MainWindow::statusEstudiante(){
    if(ptr->promedio == 10.0)
        return "Sobresaliente";
    else if(ptr->promedio <= 9.0 && ptr->promedio > 8.0)
        return "Excelente";
    else if(ptr->promedio <= 8.0 && ptr->promedio > 6.0)
        return "Regular";
    else if(ptr->promedio < 6.0)
        return "Insuficiente";

    return " ";
}
