#include "mainwindow.h"
#include "ui_mainwindow.h"

#define CANT_INIT 37

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Se asigna espacio de memoria dinamica para los graficos */
    misBarras = new QCPBars(ui->plot1->xAxis, ui->plot1->yAxis);
    miLine = new QCPGraph(ui->plot2->xAxis, ui->plot2->yAxis);

    valuesRandom(xValuesD, yValuesD, CANT_INIT); // Se asignan valores random como default al iniciar
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnDefault_clicked()
{
    /* Se eliminan datos de los graficos */
    misBarras->data()->clear();
    miLine->data()->clear();

    /* Se realiza configuracion general para los graficos */
    configGraphs(xValuesD, yValuesD);

    /* Se presentan graficos */
    ui->plot1->replot();
    ui->plot2->replot();
}

void MainWindow::on_btnRandom_clicked()
{
    /* Variables volatiles para datos dinamicos en graficos */
    QVector<double> xValues;
    QVector<double> yValues;

    misBarras->data()->clear();
    miLine->data()->clear();

    valuesRandom(xValues, yValues, CANT_INIT); // Se asignan valores random
    configGraphs(xValues, yValues);

    ui->plot1->replot();
    ui->plot2->replot();
}

void MainWindow::configGraphs(QVector<double>& x, QVector<double>& y){
    qDebug() << "x: " << x;
    qDebug() << "y: " << y;

    /* Grafico de barras */
    misBarras->setData(x, y);   // Asigna valor x e y
    ui->plot1->xAxis->setRange(0, x.last()); // Asigna limites de eje de absisas en base al ultimo elemento del QVector
    ui->plot1->yAxis->setRange(0, maxNumVector(y)); // Asigna limites de eje de ordenada en base al maximo valor en QVector

    /* Grafico de linea */
    miLine->setData(x, y);
    ui->plot2->xAxis->setRange(0, x.last());
    ui->plot2->yAxis->setRange(0, maxNumVector(y));
}

void MainWindow::on_btnClear_clicked()
{
    /* Se eliminan datos de los graficos */
    misBarras->data()->clear();
    miLine->data()->clear();

    /* Se presenta grafico sin datos */
    ui->plot1->replot();
    ui->plot2->replot();
}

/*  ----- Algoritmos -----*/

void MainWindow::valuesRandom(QVector<double>& x, QVector<double>& y, int cant){
    for(int i=0; i<cant; i++){
        x.append(i);
        y.append(QRandomGenerator::global()->generateDouble());
    }
}

double MainWindow::maxNumVector(QVector<double>& vector){
    double max = 0.0;

    for(int i=0; i< vector.size() ; i++){
        if(vector[i] > max){
            max = vector[i];
        }
    }
    return max;
}


