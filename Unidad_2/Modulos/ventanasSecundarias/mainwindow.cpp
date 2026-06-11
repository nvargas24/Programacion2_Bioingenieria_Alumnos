#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    uiWin1 = new auxiliarA(nullptr);
    uiWin2 = new auxiliarB(nullptr);
    uiWin3 = new auxiliarC(nullptr);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    uiWin1->show();
    uiWin1->raise();
}

void MainWindow::on_pushButton_2_clicked()
{
    uiWin2->show();
    uiWin2->raise();
}

void MainWindow::on_pushButton_3_clicked()
{
    uiWin3->show();
    uiWin3->raise();
}

