#include "parametros.h"
#include "ui_parametros.h"

Parametros::Parametros(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Parametros)
{
    ui->setupUi(this);

    /*
    QVector<double> x={0}, y1={0}, y2={0};

    ui->plotForma->addGraph();
    ui->plotForma->graph(0)->setPen(QPen(Qt::blue));
    ui->plotForma->graph(0)->setLineStyle(QCPGraph::lsLine);

    ui->plotForma->addGraph();
    ui->plotForma->graph(1)->setPen(QPen(Qt::red));
    ui->plotForma->graph(1)->setLineStyle(QCPGraph::lsLine);

    generatorSignal("senoidal", x, y1);
    generatorSignal("cuadrada", x, y2);

    ui->plotForma->graph(0)->setData(x, y1);
    ui->plotForma->graph(1)->setData(x, y2);

    // Ajusta los ejes para que se vean ambas líneas y refresca el lienzo
    ui->plotForma->rescaleAxes();
    ui->plotForma->replot();
    */
}

Parametros::~Parametros()
{
    delete ui;
}

void Parametros::on_sliderTension_valueChanged(int value)
{
    ui->lcdTension->display(value);
}


void Parametros::on_sliderCorriente_valueChanged(int value)
{
    ui->lcdCorriente->display(value);
}


void Parametros::on_btnAceptarConfig_clicked()
{
    accept();
}

QVector<int> Parametros::getValuesParam(){
    int valueV = ui->sliderTension->value();
    int valueI = ui->sliderCorriente->value();

    return {valueV, valueI};
}

void Parametros::generatorSignal(QString typeSignal, QVector<double>& x, QVector<double>& y)
{
    for (int i = 0; i < 101; ++i) {
        x[i] = i / 5.0 - 10;
    }

    if(typeSignal == "DC"){
        for (int i = 0; i < 101; ++i) {
            y[i] = 1.5;
        }
    }
    else if(typeSignal == "senoidal"){
        for (int i=0; i<101; ++i) {
            y[i] = qSin(x[i]);
        }
    }

    else if(typeSignal == "cuadrada"){
        for (int i=0; i<101; ++i) {
            y[i] = (qSin(x[i]) >= 0) ? 1.0 : -1.0;
        }
    }
}

