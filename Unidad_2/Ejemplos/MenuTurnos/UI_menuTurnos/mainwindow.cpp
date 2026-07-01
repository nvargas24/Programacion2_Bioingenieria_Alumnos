#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), numPaciente(0)
{
    ui->setupUi(this);

    msjHistorial={
    "[INFO] Agrega paciente a espera",
    "[INFO] Se atiende paciente",
    "[INFO] Se actualiza pacientes"
    };
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAgregar_clicked()
{
    QString inputData = ui->inputPaciente->text();

    if(!inputData.isEmpty()){
        inputData = inputData.toUpper();

        pacientes.push_back(inputData);
        numPaciente++;

        ui->inputPaciente->clear();
        updateEspera();
    }

    if(!pacientes.isEmpty()){
        ui->btnOnSiguiente->setEnabled(true);
    }

    addHistorial(msjHistorial[0]);
}


void MainWindow::on_btnOnSiguiente_clicked()
{
    QString pacientePop = pacientes.front();

    ui->labelPaciente->setText(pacientePop);
    pacientes.pop_front();
    ui->labelNumAtencion->setText(QString::number(numPaciente-pacientes.size()));

    updateEspera();

    if(pacientes.isEmpty()){
        ui->btnOnSiguiente->setEnabled(false);
    }

    addHistorial(msjHistorial[1] + ": "+pacientePop);
}

void MainWindow::updateEspera(){
    ui->listEspera->clear();
    ui->listEspera->addItems(pacientes);
    ui->listEspera->scrollToBottom();

    addHistorial(msjHistorial[2]);
}

void MainWindow::on_inputPaciente_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        ui->btnAgregar->setEnabled(true);
    }
    else{
        ui->btnAgregar->setEnabled(false);
    }
}

void MainWindow::addHistorial(QString msj){
    ui->listHistorial->addItem(msj);
    ui->listHistorial->scrollToBottom();
}
