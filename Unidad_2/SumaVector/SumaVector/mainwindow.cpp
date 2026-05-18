#include "mainwindow.h"
#include "ui_mainwindow.h"

Vector operator+(const Vector &a, const Vector &b){

    Vector resultado;

    resultado.x = a.x + b.x;
    resultado.y = a.y + b.y;

    return resultado;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSuma_clicked()
{
    QString resultado;
    Vector a;
    Vector b;

    // Extraer datos desde QLineEdit
    a.x = ui->x_vecA->text().toInt();
    a.y = ui->y_vecA->text().toInt();

    b.x = ui->x_vecB->text().toInt();
    b.y = ui->y_vecB->text().toInt();

    // Suma de vectores
    Vector c = a + b;

    // Mostrar resultado
    resultado = "("
                + QString::number(c.x)
                + ", "
                + QString::number(c.y)
                + ")";

    ui->resultadoSuma->setText(resultado);
}


void MainWindow::on_btnLimpiar_clicked()
{
    // Limpiar Vector A
    ui->x_vecA->clear();
    ui->y_vecA->clear();

    // Limpiar Vector B
    ui->x_vecB->clear();
    ui->y_vecB->clear();

    // Limpiar resultado
    ui->resultadoSuma->clear();
}

