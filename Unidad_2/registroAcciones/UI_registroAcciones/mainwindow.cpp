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

void MainWindow::on_btnIngresar_clicked()
{
    acciones.push(ui->inAcciones->text());
    qDebug() << "[INFO] Se carga a stack: " << acciones.top();
}

void MainWindow::on_btnTodo_clicked()
{
    QStringList misAcciones;

    ui->labelUltima->setText(acciones.top());
    while(! acciones.empty()){
        qDebug() << "Ultima accion: " << acciones.top();
        misAcciones.prepend(acciones.top());
        acciones.pop();
    }

    qDebug() << "[INFO] Stack vacio ";
    ui->listAcciones->addItems(misAcciones);
}


void MainWindow::on_btnUltimo_clicked()
{
    ui->labelUltima->setText(acciones.top());
    qDebug() << "[INFO] Mostrar ultimo elemento de stack ";
}


void MainWindow::on_inAcciones_returnPressed()
{
    MainWindow::on_btnIngresar_clicked();
}

