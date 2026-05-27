#include "mainwindow.h"
#include "ui_mainwindow.h"


#include<QStandardItemModel>
#include<QTextStream>
#include<QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mModel = new QStandardItemModel(this);
    ui->tableView->setModel(mModel);
    setCentralWidget(ui->tableView);
    //setWindowTitle("CSV Viewer");

    // Lectura de archivo .CSV
    QString filename = "C:/Users/nahue/Documents/Workspace/Bioingenieria - Programacion2/Archivos_free/datos_biomedicos1.csv";  //ingresado por usuario
    QFile file(filename); // se inicializa objeto con la url

    // Verifico que exista dicho archivo
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream xin(&file); // Habilito flujo con archivo por medio de xin

    int row = 0;
    while(!xin.atEnd()){
        QString line = xin.readLine();
        // Descrimina columnas por ","
        QStringList values = line.split(",");
        // Determina cuantas columnas se tiene
        const int colCount = values.size();

        mModel->insertRow(row); // se crea fila en posicion 0, y luego incrementa hasta finalizar lectura de archivo
        // Cargo datos en la fila asignada, recorriendo cada columna
        for(int col=0; col<colCount; col++){
            QStandardItem *item = new QStandardItem(values[col]); // Objeto que lee valor en ubicacion fila-columna indicada
            mModel->setItem(row, col, item); // Se carga valor anterior en la correspondiente fila-columna en QTableView
        }
        row++; // Avanzo a siguiente fila de .csv
    }
    file.close();

}

MainWindow::~MainWindow()
{
    delete ui;
}
