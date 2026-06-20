#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    movimientos={
      "[INFO] Actualiza elementos de QComboBox",
      "[INFO] Abre ventana 'Parametros'",
      "[INFO] Cierra ventana 'Parametros'",
      "[INFO] Abre ventana 'Modelos'",
      "[INFO] Cierra ventana 'Modelos'",
      "[INFO] Actualiza datos de fuente",
      "[INFO] Actualiza parametros de fuente",
      "[ADVERTENCIA] Habilita salida",
      "[ADVERTENCIA] Deshabilita salida"
    };

    /* Reservo memoria para ventanas secundarias */
    uiWinParametros = new Parametros(nullptr);
    uiWinModelos = new Modelos(nullptr);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnModeloG_clicked()
{
    // listado de elementos para QComboBox
    uiWinModelos->setListMarcas({"Tektronik", "UniT", "KeySight"});
    addMovimientos(movimientos[0]);

    ui->listMovimientos->addItem(movimientos[3]);
    if(uiWinModelos->exec() == QDialog::Accepted){
        addMovimientos(movimientos[4]);

        modeloSelect = uiWinModelos->getModelo();
        ui->labelDatosG->setText(modeloSelect[0] + " " +modeloSelect[1]);
        addMovimientos(movimientos[5]);
    }
}

void MainWindow::on_btnParametrosG_clicked()
{
    ui->listMovimientos->addItem(movimientos[1]);
    if(uiWinParametros->exec() == QDialog::Accepted){
        addMovimientos(movimientos[2]);

        paramSelect = uiWinParametros->getValuesParam();
        ui->labelParametrosG->setText(QString::number(paramSelect[0])+"V - " + QString::number(paramSelect[1])+"A");
        addMovimientos(movimientos[6]);
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
        addMovimientos(movimientos[7]);

    }
    else{
        ui->btnStatusG->setText("Habilitar salida");
        ui->ledStatusG->setStyleSheet("	background-color: rgb(255, 0, 0); \
                                        border-radius: 19px; \
                                        border: 2px solid black;");
        addMovimientos(movimientos[8]);
    }
}


void MainWindow::closeEvent(QCloseEvent* event){
    if(uiWinModelos) uiWinModelos->close();
    if(uiWinParametros) uiWinParametros->close();
}

void MainWindow::addMovimientos(QString msj){
    ui->listMovimientos->addItem(msj);
    ui->listMovimientos->scrollToBottom();
}
