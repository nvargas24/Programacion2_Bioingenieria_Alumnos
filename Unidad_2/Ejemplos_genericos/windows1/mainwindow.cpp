#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    win2 = new winNuevo(nullptr);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnNuevo_clicked()
{
    win2->show();
    win2->raise();

    if(win2->exec()==QDialog::Accepted){
        qDebug() << "[WIN2] Selecciono 'Quiero'";
    }
    else{
        qDebug() << "[WIN2] Selecciono 'Ignorar'";
    }
}

