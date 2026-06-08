#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    win2 = new winNuevo(nullptr); // Inicializo puntero con espacio de memoria dinamica para ventana
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnNuevo_clicked()
{
    win2->show(); // Muestra ventana secundaria
    win2->raise(); // Ubica ventana secundaria delante de la mainwindow

    // Aplicacion queda ejecutando UI sencudaria por exec()
    // Dialog por default envia 2 señales: 'Accept' y 'Reject'
    // OBS.: Se puede personalizar otras señales

    if(win2->exec()==QDialog::Accepted){
        qDebug() << "[WIN2] Selecciono 'Quiero'"; // se ejecuta a capturar señal 'Accept'
    }
    else{
        qDebug() << "[WIN2] Selecciono 'Ignorar'"; // se ejecuta a capturar señal 'Reject'
    }
}

