#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Se utiliza nullptr para que sea una ventana independiente de la mainwindow
    win2 = new winNuevo(nullptr); // Inicializo puntero con espacio de memoria dinamica para ventana
    win3 = new winAuxiliar(nullptr); // Inicializo puntero con espacio de memoria dinamiza para otra ventana
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnNuevo_clicked()
{
    QString inNombreWin2; // almacena dato de otro widget

    win2->show();
    win2->raise();

    if(win2->exec()==QDialog::Accepted){
        inNombreWin2 = win2->getNombre(); // Se extrae dato de widget en otra ventana
        qDebug() << "[MainWindow] Importado de WIN2: " << inNombreWin2;

        win3->setNombre(inNombreWin2); // Se carga en QList de ventana auxiliar
        qDebug() << "[MainWindow] Exportado texto a WINAUXIULIAR";
    }

}


void MainWindow::on_btnControl_clicked()
{
    win3->show();
    win3->raise();
}

