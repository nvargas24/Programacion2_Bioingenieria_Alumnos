#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setSaldo(1000); // Ingreso saldo inicial

    /* Listado de mensajes posibles en QListWidget*/
    movimientos = {
        "[INFO] Deposito valido",
        "[ERROR] Deposito no valido",
        "[INFO] Saldo actualizado"
    };
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSaldo(int saldo){
    this->saldoActual = saldo; // Actualiza atributo privado de saldo
    ui->viewSaldo->setText(QString::number(saldoActual)); // Actualiza el widget
}

void MainWindow::on_btnVerSaldo_pressed()
{
    ui->viewSaldo->setEchoMode(QLineEdit::Normal); // Permite visualizar el saldo
}

void MainWindow::on_btnVerSaldo_released()
{
    ui->viewSaldo->setEchoMode(QLineEdit::Password); // Oculta el saldo
}

void MainWindow::on_btnDepositar_clicked()
{
    int deposito;

    deposito = ui->inIngreso->text().toInt(); // Ingreso de monto nuevo
    ui->inIngreso->clear(); // Se limpia campo

    // Validacion de monto ingresado
    if(validacionSaldo(deposito)){
        this->saldoActual += deposito;  // Se incorora nuevo monto al actual

        QMessageBox::information(this, "Deposito", "Se actualizo su saldo $"+QString::number(saldoActual));
        ui->listMovimientos->addItem(movimientos[2]); // Se carga mensaje 3 en QListWidget
        ui->listMovimientos->scrollToBottom(); // Se orienta a scroll que esta al final del QListWidget
        ui->viewSaldo->setText(QString::number(saldoActual)); // Se actualiza saldo oculto
    }
}

bool MainWindow::validacionSaldo(int deposito){
    /* Solo se considera un monto de deposito valido si es mayor a 0 */
    if(deposito > 0){
        QMessageBox::information(this, "Deposito", "Deposito valido");
        ui->listMovimientos->addItem(movimientos[0]);
        ui->listMovimientos->scrollToBottom();
        return true;
    }
    else{
        QMessageBox::critical(this, "Deposito", "Deposito no valido");
        ui->listMovimientos->addItem(movimientos[1]);
        ui->listMovimientos->scrollToBottom();
        return false;
    }
}

