#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Reservo memoria para ventanas secundarias */
    uiWinParametros = new Parametros(this);
    uiWinModelos = new Modelos(nullptr);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnModeloG_clicked()
{
    uiWinModelos->show();
}


void MainWindow::on_btnParametrosG_clicked()
{
    uiWinParametros->show();
}

