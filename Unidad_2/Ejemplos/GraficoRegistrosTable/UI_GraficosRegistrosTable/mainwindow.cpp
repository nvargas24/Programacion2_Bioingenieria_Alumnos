#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Configuracion de grafico a mostrar
    ui->widget->addGraph(); // blue line
    ui->widget->graph(0)->setPen(QPen(QColor(40, 110, 255), 3));
    ui->widget->xAxis->setLabel("Meas");

    ui->widget->xAxis->setRange(0, 50);
    ui->widget->axisRect()->setupFullAxesBox();
    ui->widget->yAxis->setRange(0, 100);

    // Conecta a Qtimer
    connect(&dataTimer, &QTimer::timeout, this, &MainWindow::updatePlot);
    dataTimer.start(100); // cada 100 ms (10 Hz)

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::on_verticalSlider_valueChanged(int value)
{
    ui->lcdNumber->display(value);

    static double x = 0;

    // Agregar punto al gráfico
    ui->widget->graph(0)->addData(x, value);

    // Incrementar eje X
    x += 1;

    // Mantener ventana visible (scroll)
    ui->widget->xAxis->setRange(x, 50, Qt::AlignRight);

    // Redibujar
    ui->widget->replot();
}
*/
void MainWindow::updatePlot()
{
    static double x = 0;
    // Obtengo valor de QSlider
    int value = ui->verticalSlider->value();
    // Muestro en display
    ui->lcdNumber->display(value);
    // Muestro en grafico
    ui->widget->graph(0)->addData(x, value);
    // Incremento la posicion X en 1 para tener un grafico continuo
    x += 1;

    // Ajusto eje a la derecha
    ui->widget->xAxis->setRange(x, 50, Qt::AlignRight);
    // Elimina grafico viejo para no sobrecargar la memoria
    ui->widget->graph(0)->data()->removeBefore(x - 50);

    ui->widget->replot();

    // Actualizo Tabla
    ui->tableWidget->setItem(row, 0 , new QTableWidgetItem(QString::number(x)));
    ui->tableWidget->setItem(row, 1 , new QTableWidgetItem(QString::number(value)));

    row++;

    if(row >= 12){
        ui->tableWidget->insertRow(row);
        ui->tableWidget->scrollToBottom();
    }
}

