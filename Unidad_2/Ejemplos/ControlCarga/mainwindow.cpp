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

void MainWindow::on_sliderCarga1_valueChanged(int value)
{
    ui->dialCarga1->setValue(value);
    ui->sboxCarga1->setValue(value);
    ui->lcdCarga1->display(value);
}

void MainWindow::on_sliderCarga2_valueChanged(int value)
{
    ui->dialCarga2->setValue(value);
    ui->sboxCarga2->setValue(value);
    ui->lcdCarga2->display(value);
}


void MainWindow::on_dialCarga1_valueChanged(int value)
{
    ui->sliderCarga1->setValue(value);
    ui->sboxCarga1->setValue(value);
    ui->lcdCarga1->display(value);
}


void MainWindow::on_dialCarga2_valueChanged(int value)
{
    ui->sliderCarga2->setValue(value);
    ui->sboxCarga2->setValue(value);
    ui->lcdCarga2->display(value);
}


void MainWindow::on_sboxCarga1_valueChanged(int value)
{
    ui->sliderCarga1->setValue(value);
    ui->dialCarga1->setValue(value);
    ui->lcdCarga1->display(value);
}

void MainWindow::on_sboxCarga2_valueChanged(int value)
{
    ui->sliderCarga2->setValue(value);
    ui->dialCarga2->setValue(value);
    ui->lcdCarga2->display(value);
}

