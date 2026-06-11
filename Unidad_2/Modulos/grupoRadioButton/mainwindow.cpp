#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_numeros_buttonClicked()
{
    QAbstractButton* selectRbtnNumero;
    QList<QAbstractButton*> listRbtnNumeros;
    QAbstractButton* radioButton;

    // Indica cual QRadioButton del grupo se selecciono
    selectRbtnNumero = ui->numeros->checkedButton();
    qDebug()<< "QRadioButton: " << selectRbtnNumero;

    // Muestra texto del QRadioButton
    qDebug()<< "Texto de QRadioButton seleccionado: " << selectRbtnNumero->text();

    // Mostrar todos los textos de cada QRadioButton del grupo
    qDebug()<< "------ Listado de qradiobutton en grupo Numeros ------";
    listRbtnNumeros = ui->numeros->buttons(); // Se obtiene listado de QRadioButton del grupo
    for(int i=0; i < listRbtnNumeros.size(); i++){
        radioButton = listRbtnNumeros[i];
        qDebug()<< radioButton->text();
    }
}

void MainWindow::on_letras_buttonClicked()
{
    QAbstractButton* selectRbtnLetra;
    QList<QAbstractButton*> listRbtnLetras;
    QAbstractButton* radioButton;

    // Indica cual QRadioButton del grupo se selecciono
    selectRbtnLetra = ui->letras->checkedButton();
    qDebug()<< "QRadioButton: " << selectRbtnLetra;

    // Muestra texto del QRadioButton
    qDebug()<< "Texto de QRadioButton seleccionado: " << selectRbtnLetra->text();

    // Mostrar todos los textos de cada QRadioButton del grupo
    qDebug()<< "------ Listado de qradiobutton en grupo Letras ------";
    listRbtnLetras = ui->letras->buttons(); // Se obtiene listado de QRadioButton del grupo
    for(int i=0; i < listRbtnLetras.size(); i++){
        radioButton = listRbtnLetras[i];
        qDebug()<< radioButton->text();
    }
}


