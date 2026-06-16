#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    valuesRandom(xValues, yValues, 100);

    qDebug() << xValues;
    qDebug() << yValues;

    QCPBars* misBarras = new QCPBars(ui->plot1->xAxis, ui->plot1->yAxis);
    QCPGraph* miLine = new QCPGraph(ui->plot2->xAxis, ui->plot2->yAxis);

    misBarras->setData(xValues, yValues);
    miLine->setData(xValues, yValues);

    ui->plot1->xAxis->setRange(0, 100);
    ui->plot1->yAxis->setRange(0, 1.1);

    ui->plot2->xAxis->setRange(0, 100);
    ui->plot2->yAxis->setRange(0, 1.1);

    ui->plot1->replot();
    ui->plot2->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::valuesRandom(QVector<double>& x, QVector<double>& y, int cant){
    for(int i=0; i<cant; i++){
        x.append(i);
        y.append(QRandomGenerator::global()->generateDouble());
    }
}
