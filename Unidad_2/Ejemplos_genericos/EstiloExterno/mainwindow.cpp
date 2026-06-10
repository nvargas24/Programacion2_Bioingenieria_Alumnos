#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QSizeGrip>
#include <QGridLayout>
#include <QStatusBar>

void MainWindow::mousePressEvent(QMouseEvent *event) {
    // Detecta el click izquierdo solo si ocurre dentro de la barra de título
    if (event->button() == Qt::LeftButton && ui->barraTitulo->geometry().contains(event->pos())) {
        m_mousePosition = event->globalPosition().toPoint() - this->frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    // Mueve la ventana si el botón izquierdo sigue presionado
    if (event->buttons() & Qt::LeftButton && ui->barraTitulo->geometry().contains(event->pos())) {
        this->move(event->globalPosition().toPoint() - m_mousePosition);
        event->accept();
    }
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);


    // Las 3 líneas definitivas:
    QStatusBar *statusBar = new QStatusBar(this);
    this->setStatusBar(statusBar); // Se clava abajo automáticamente
    statusBar->setSizeGripEnabled(true);

    // Botones minimizar, maximizar y cerrar
    connect(ui->btnMaximizar, &QPushButton::clicked, this, [this]() {
        isMaximized() ? showNormal() : showMaximized();
    });

    connect(ui->btnMinimizar, &QPushButton::clicked,
            this, &QWidget::showMinimized);

    connect(ui->btnCerrar, &QPushButton::clicked,
            this, &QWidget::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}
