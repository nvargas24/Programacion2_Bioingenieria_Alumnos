#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pbarCarga->setMaximum(ui->sliderCarga->maximum());
    ui->rbtnCarga->setChecked(true);

    listColores = {"rojo", "amarillo", "violeta", "verde", "azul"};
    listAnimales = {"leon", "ballena", "tortuga", "elefante", "caballo"};
    listCosas = {"sobrero", "canilla", "piedra", "computadora", "cartel"};

    listRegistros = {"[INFO] Ingresa listado colores",
                    "[INFO] Ingresa listado animales",
                    "[INFO] Ingresa listado cosas",
                    "[INFO] Elimina listado colores",
                    "[INFO] Elimina listado animales",
                    "[INFO] Elimina listado cosas",
                    "[INFO] Selecciona elemento: ",
                    };
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinNum_valueChanged(int arg1)
{
    ui->lcdNum->display(arg1);
    ui->labelNum->setNum(arg1);
}

// estructura de slot para detectar señales :
// void MainWindow::on_[identificador de widget]_[señal]();

void MainWindow::on_grbtnEnabled_idClicked(int id){
    QString enabled;

    qDebug()<< "id: " << id;
    qDebug()<< "texto: " << ui->grbtnEnabled->button(id)->text();

    enabled = ui->grbtnEnabled->button(id)->text(); // Obtiene text de QRadioButton

    // Se de/habilita QGroup segun QRadioButton
    if(enabled == "Carga"){
        ui->gboxCarga->setEnabled(true);
        ui->gboxControl->setEnabled(false);
        ui->gboxRegistro->setEnabled(false);
    }
    else if(enabled == "Control"){
        ui->gboxCarga->setEnabled(false);
        ui->gboxControl->setEnabled(true);
        ui->gboxRegistro->setEnabled(false);
    }
    else if(enabled == "Registro"){
        ui->gboxCarga->setEnabled(false);
        ui->gboxControl->setEnabled(false);
        ui->gboxRegistro->setEnabled(true);
    }
}

void MainWindow::on_sliderCarga_valueChanged(int value)
{
    ui->pbarCarga->setValue(value);
}

void MainWindow::on_checkColores_toggled(bool checked)
{
    if(checked){
        ui->cboxOpciones->addItems(listColores);
        ui->listHistorial->addItem(listRegistros[0]);
        ui->listHistorial->scrollToBottom();
    }
    else{
        clearCboxOpciones(listColores);
        ui->listHistorial->addItem(listRegistros[3]);
        ui->listHistorial->scrollToBottom();
    }
}


void MainWindow::on_checkAnimales_toggled(bool checked)
{
    if(checked){
        ui->cboxOpciones->addItems(listAnimales);
        ui->listHistorial->addItem(listRegistros[1]);
        ui->listHistorial->scrollToBottom();
    }
    else{
        clearCboxOpciones(listAnimales);
        ui->listHistorial->addItem(listRegistros[4]);
        ui->listHistorial->scrollToBottom();
    }
}


void MainWindow::on_checkCosas_toggled(bool checked)
{
    if(checked){
        ui->cboxOpciones->addItems(listCosas);
        ui->listHistorial->addItem(listRegistros[2]);
        ui->listHistorial->scrollToBottom();
    }
    else{
        clearCboxOpciones(listCosas);
        ui->listHistorial->addItem(listRegistros[5]);
        ui->listHistorial->scrollToBottom();
    }
}



void MainWindow::clearCboxOpciones(QStringList list)
{
    //for(QString& elemento : list){
    for(int i=0; i<list.size(); i++){
        int indice = ui->cboxOpciones->findText(list[i]);
        if(indice != -1){
            ui->cboxOpciones->removeItem(indice);
        }
    }
}


void MainWindow::on_cboxOpciones_textActivated(const QString &arg1)
{
    ui->listHistorial->addItem(listRegistros[6] + arg1);
    ui->listHistorial->scrollToBottom();
}

