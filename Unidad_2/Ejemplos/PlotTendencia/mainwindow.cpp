#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , values({0.0, 0.0, 0.0, 0.0, 0.0})
    , listLabel({"Nike", "Adidas", "Puma", "Reebok", "Topper"}) // Inicialización correcta de tu QVector
{
    ui->setupUi(this);

    ejeRadial = new QValueAxis();
    radar = new QPolarChart();
    series1 = new QLineSeries();
    etiquetaAngular = new QCategoryAxis();

    // Configura el eje angular de marcas de texto
    etiquetaAngular->setRange(0, 360);
    etiquetaAngular->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue); // Centra el texto en la línea

    /* Borra fondo y contorno del QPolarChart */
    radar->setBackgroundBrush(Qt::NoBrush);
    radar->setBackgroundPen(Qt::NoPen);

    configGraphPolar(values);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configGraphPolar(QList<double>& val){
    double maxValueList = maxNumVector(val);
    double pasoAngular = 360.0 / listLabel.size();
    double anguloActual;

    series1->clear();

    for(int i = 0; i < listLabel.size(); i++){
        anguloActual = i * pasoAngular;
        series1->append(anguloActual, val[i]);
        etiquetaAngular->append(listLabel[i], anguloActual);
    }
    series1->append(360.0, val.first());

    // Añade la serie al gráfico antes de manipular los ejes
    radar->addSeries(series1);
    radar->setTitle("Análisis de Marcas");

    // Configura el eje radial (escalas concéntricas de fondo)
    ejeRadial->setRange(0, std::ceil(maxValueList)); // Escala hasta el valor maximo
    ejeRadial->setTickCount(4); // Líneas de nivel: 0, 2, 4, 6
    ejeRadial->setLabelFormat("%.2f");

    // Vincula ambos ejes de forma definitiva al gráfico
    radar->addAxis(etiquetaAngular, QPolarChart::PolarOrientationAngular);
    radar->addAxis(ejeRadial, QPolarChart::PolarOrientationRadial);
    series1->attachAxis(etiquetaAngular);
    series1->attachAxis(ejeRadial);

    // Optimización de espacio en el widget promovido de la UI
    radar->setMargins(QMargins(0, 0, 0, 0));
    radar->legend()->setVisible(false);

    ui->polarGraph->setChart(radar);
    ui->polarGraph->setRenderHint(QPainter::Antialiasing); // Suaviza los bordes de la telaraña
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


void MainWindow::on_sliderNike_valueChanged(int value)
{
    values[0] = value;
    configGraphPolar(values);
}


void MainWindow::on_sliderAdidas_valueChanged(int value)
{
    values[1] = value;
    configGraphPolar(values);
}


void MainWindow::on_sliderPuma_valueChanged(int value)
{
    values[2] = value;
    configGraphPolar(values);
}


void MainWindow::on_sliderReebok_valueChanged(int value)
{
    values[3] = value;
    configGraphPolar(values);
}


void MainWindow::on_sliderTopper_valueChanged(int value)
{
    values[4] = value;
    configGraphPolar(values);
}

