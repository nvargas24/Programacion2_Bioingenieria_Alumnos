#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_red_clicked()
{
    ui->LED->setStyleSheet(
        "background-color: red;"
        "border-radius: 30px;"
        "border: 2px solid black;"
        );
}

void MainWindow::on_btn_green_clicked()
{
    ui->LED->setStyleSheet(
        "background-color: green;"
        "border-radius: 30px;"
        "border: 2px solid black;"
        );
}

void MainWindow::on_btn_blue_clicked()
{
    ui->LED->setStyleSheet(
        "background-color: blue;"
        "border-radius: 30px;"
        "border: 2px solid black;"
        );
}

