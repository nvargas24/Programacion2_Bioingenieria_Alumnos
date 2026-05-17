#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->setWindowTitle("Signls & Slots");
    this->resize(600, 250);

    QPushButton* btn = new QPushButton("Salir", this);
    btn->setGeometry(10, 10, 120, 30);

    QObject::connect(btn, &QPushButton::clicked, this, &QMainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

