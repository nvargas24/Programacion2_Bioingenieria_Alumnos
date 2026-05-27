#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    // QPushButton *boton2 = new QPushButton("Presionar", this);
    // boton2 -> setGeometry(50,450,80,30);

    // connect(boton2, &QPushButton::clicked, this, [=]() {
    //     QMessageBox::information(this, "Mensaje", "Hiciste clic en boton2.");
    // });

}

MainWindow::~MainWindow()
{
    delete ui;
}
