#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Reservo memoria para ventanas secundarias */
    uiWinParametros = new Parametros(this);
    uiWinModelos = new Modelos(nullptr);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnModeloG_clicked()
{
    uiWinModelos->setListMarcas({"Tektrokik", "UniT", "keySight"});

    if(uiWinModelos->exec() == QDialog::Accepted){
        modeloSelect = uiWinModelos->getModelo();
        qDebug() << "modeloSelect: " << modeloSelect;
        ui->labelParametrosG->setText(modeloSelect[0] + modeloSelect[1]);
    }
}

void MainWindow::on_btnParametrosG_clicked()
{
    if(uiWinParametros->exec() == QDialog::Accepted){
        paramSelect = uiWinParametros->getValuesParam();
        qDebug() << "paramSelect: " << paramSelect;
        ui->labelDatosG->setText(QString::number(paramSelect[0])+"V - " + QString::number(paramSelect[1])+"A");
    }
}

void MainWindow::setUserLogin(QString user){
    ui->labelUsuario->setText(user);
}

void MainWindow::on_btnStatusG_toggled(bool checked)
{
    if(checked){
        ui->btnStatusG->setText("Deshabilitar salida");
        ui->ledStatusG->setStyleSheet("	background-color: rgb(0, 255, 0); \
                                        border-radius: 19px; \
                                        border: 2px solid black;");
    }
    else{
        ui->btnStatusG->setText("Habilitar salida");
        ui->ledStatusG->setStyleSheet("	background-color: rgb(255, 0, 0); \
                                        border-radius: 19px; \
                                        border: 2px solid black;");
    }
}

