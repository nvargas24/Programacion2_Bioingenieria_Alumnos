#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), valueCarga1(0), valueCarga2(0) // solo para evitar basura
{
    ui->setupUi(this);

    // Obtengo cada control de carga
    maxGeneral = ui->sboxCarga1->maximum() + ui->sboxCarga2->maximum();

    // opcional: si fuesen distintos, antes de que usuario acceda ya
    //           ya se puede asignar el max a todos los widgets
    ui->dialCarga1->setMaximum(ui->sboxCarga1->maximum());
    ui->sboxCarga1->setMaximum(ui->sboxCarga1->maximum());

    ui->dialCarga2->setMaximum(ui->sboxCarga2->maximum());
    ui->sboxCarga2->setMaximum(ui->sboxCarga2->maximum());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sliderCarga1_valueChanged(int value)
{
    ui->dialCarga1->setValue(value);
    ui->sboxCarga1->setValue(value);
    ui->lcdCarga1->display(value);

    // carga de progressBar
    valueCarga1 = value;
    per = ((valueCarga1+valueCarga2)/(maxGeneral*1.0)) *100;
    ui->pbarGeneral->setValue(static_cast<int>(per));
}


void MainWindow::on_dialCarga1_valueChanged(int value)
{
    ui->sliderCarga1->setValue(value);
    ui->sboxCarga1->setValue(value);
    ui->lcdCarga1->display(value);
}


void MainWindow::on_sboxCarga1_valueChanged(int value)
{
    ui->sliderCarga1->setValue(value);
    ui->dialCarga1->setValue(value);
    ui->lcdCarga1->display(value);
}

void MainWindow::on_sliderCarga2_valueChanged(int value)
{
    ui->dialCarga2->setValue(value);
    ui->sboxCarga2->setValue(value);
    ui->lcdCarga2->display(value);

    // carga de progressBar
    valueCarga2 = value;
    per = ((valueCarga1+valueCarga2) / (maxGeneral*1.0)) *100;
    ui->pbarGeneral->setValue(static_cast<int>(per));
}


void MainWindow::on_dialCarga2_valueChanged(int value)
{
    ui->sliderCarga2->setValue(value);
    ui->sboxCarga2->setValue(value);
    ui->lcdCarga2->display(value);
}


void MainWindow::on_sboxCarga2_valueChanged(int value)
{
    ui->sliderCarga2->setValue(value);
    ui->dialCarga2->setValue(value);
    ui->lcdCarga2->display(value);
}



