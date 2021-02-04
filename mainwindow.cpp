#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(-500,-200,1000,400);

    ui->campo->setScene(scene);
    ui->centralwidget->adjustSize();

    this->canionD=new Caniongraf(30,1.2,new Posicion(-100,0),true);
    this->canionD->setEscala(0.5);

    this->canionO=new Caniongraf(30,1.2,new Posicion(100,0),false);
    this->canionO->setEscala(0.5);

    scene->addItem(this->canionD);
    scene->addItem(this->canionO);
}


MainWindow::~MainWindow()
{
    delete ui;
}

float MainWindow::calcularD()
{

}

void MainWindow::mostrarinfo(Bala bala)
{

}

void MainWindow::Caso1()
{

}

void MainWindow::Caso2()
{

}

void MainWindow::Caso3()
{

}

void MainWindow::Caso4()
{

}

void MainWindow::Caso5()
{

}

bool MainWindow::impacto(Posicion canionxy, Posicion balaxy)
{

}

