#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), modepbar("Ambos"),
    per(0), maxGeneral(1.0), valueCarga1(0), valueCarga2(0)
{
    ui->setupUi(this);
    uiModos = new Modos(nullptr);
    uiLimites = new Limites(nullptr);

    maxGeneral = ui->sliderCarga1->maximum() + ui->sliderCarga2->maximum();
    setNewValuePBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sliderCarga1_valueChanged(int value)
{
    ui->dialCarga1->setValue(value);
    ui->sboxCarga1->setValue(value);
    ui->lcdCarga1->display(value);

    valueCarga1 = ui->sliderCarga1->value();

    setNewValuePBar();
}

void MainWindow::on_sliderCarga2_valueChanged(int value)
{
    ui->dialCarga2->setValue(value);
    ui->sboxCarga2->setValue(value);
    ui->lcdCarga2->display(value);

    valueCarga2 = ui->sliderCarga2->value();

    setNewValuePBar();
}


void MainWindow::on_dialCarga1_valueChanged(int value)
{
    ui->sliderCarga1->setValue(value);
    ui->sboxCarga1->setValue(value);
    ui->lcdCarga1->display(value);
}


void MainWindow::on_dialCarga2_valueChanged(int value)
{
    ui->sliderCarga2->setValue(value);
    ui->sboxCarga2->setValue(value);
    ui->lcdCarga2->display(value);
}


void MainWindow::on_sboxCarga1_valueChanged(int value)
{
    ui->sliderCarga1->setValue(value);
    ui->dialCarga1->setValue(value);
    ui->lcdCarga1->display(value);
}

void MainWindow::on_sboxCarga2_valueChanged(int value)
{
    ui->sliderCarga2->setValue(value);
    ui->dialCarga2->setValue(value);
    ui->lcdCarga2->display(value);
}


void MainWindow::on_btnLimites_clicked()
{
    // Extrae limites de QSlider, ya que estan todos conectados no es necesario ver cada uno
    rangoLimites = {ui->sliderCarga1->minimum(), ui->sliderCarga1->maximum()};
    uiLimites->setLimites(rangoLimites); // se carga en ventana secundaria

    // Muestra ventana secundaria
    // Importa datos de ventana secundaria
    if(uiLimites->exec() == QDialog::Accepted){  // Confirmado por ventana secundaria se importa datos
        rangoLimites = uiLimites->getLimites();  // (min , max)

        // setear nuevos maximos y minimos
        setNewLim();
        qDebug() << "Limites: " << rangoLimites;
        maxGeneral = ui->sliderCarga1->maximum() + ui->sliderCarga2->maximum();

        setNewValuePBar();
        qDebug()<< "Carga a PROGRESS BAR: "<< per;

    }
}

void MainWindow::setNewLim(){
    int min = rangoLimites[0];
    int max = rangoLimites[1];

    // Cargo nuevos minimos
    ui->sliderCarga1->setMinimum(min);
    ui->dialCarga1->setMinimum(min);
    ui->sboxCarga1->setMinimum(min);

    ui->sliderCarga2->setMinimum(min);
    ui->dialCarga2->setMinimum(min);
    ui->sboxCarga2->setMinimum(min);

    // Cargo nuevos maximos
    ui->sliderCarga1->setMaximum(max);
    ui->dialCarga1->setMaximum(max);
    ui->sboxCarga1->setMaximum(max);

    ui->sliderCarga2->setMaximum(max);
    ui->dialCarga2->setMaximum(max);
    ui->sboxCarga2->setMaximum(max);
}


void MainWindow::on_btnModos_clicked()
{
    // Se carga modo actual a ventana secundaria
    uiModos->setModo(modepbar);

    // Muestra ventana secundaria
    uiModos->show();
    uiModos->raise();

    // Al confirmar se obtiene modo de operacion de la QProgressBar
    if(uiModos->exec() == QDialog::Accepted){
        modepbar = uiModos->getModo();
    }

    setNewValuePBar();
}

void MainWindow::setNewValuePBar(){
    if(modepbar == "Ambos"){
        per = ((valueCarga1+valueCarga2) / (maxGeneral*1.0)) *100;
    }
    else if(modepbar == "Solo carga 1"){
        per = (valueCarga1 / (ui->sliderCarga1->maximum()*1.0) )*100;
    }
    else if(modepbar == "Solo carga 2"){
        per = (valueCarga2 / (ui->sliderCarga2->maximum()*1.0)) *100;
    }

    ui->pbarGeneral->setValue(static_cast<int>(per));
}


void MainWindow::on_btnColor_pressed()
{
    ui->groupBoxAjuste->setStyleSheet("background-color: #A89499;");
}


void MainWindow::on_btnColor_released()
{
    ui->groupBoxAjuste->setStyleSheet("background-color: #F3F3F3;");
}


void MainWindow::on_cboxSlider_toggled(bool checked)
{
    ui->sliderCarga1->setEnabled(checked);
    ui->sliderCarga2->setEnabled(checked);
}


void MainWindow::on_cboxDial_toggled(bool checked)
{
    ui->dialCarga1->setEnabled(checked);
    ui->dialCarga2->setEnabled(checked);
}


void MainWindow::on_cboxSpin_toggled(bool checked)
{
    ui->sboxCarga1->setEnabled(checked);
    ui->sboxCarga2->setEnabled(checked);
}

