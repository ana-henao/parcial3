#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "math.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer1=new QTimer(this);
    timer2=new QTimer(this);
    timer3=new QTimer(this);
    timer4=new QTimer(this);
    timer5=new QTimer(this);


    scene = new QGraphicsScene(this);
    scene->setSceneRect(-500,-200,1000,400);

    ui->campo->setScene(scene);
    ui->centralwidget->adjustSize();

    this->canionD=new Caniongraf(30,1.2,new Posicion(-100,0),true);
    this->canionD->setEscala(0.5);

    this->canionO=new Caniongraf(30,1.2,new Posicion(150,0),false);
    this->canionO->setEscala(0.5);

    scene->addItem(this->canionD);
    scene->addItem(this->canionO);


    timer1->stop();
//    timer2->stop();
//    timer3->stop();
//    timer4->stop();
//    timer5->stop();

    connect(timer1,SIGNAL(timeout()),this,SLOT(Caso1()));
//    connect(timer2,SIGNAL(timeout()),this,SLOT(caso2()));
//    connect(timer3,SIGNAL(timeout()),this,SLOT(caso3()));
//    connect(timer4,SIGNAL(timeout()),this,SLOT(caso4()));
//    connect(timer5,SIGNAL(timeout()),this,SLOT(caso5()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

float MainWindow::calcularD()
{
    float xD=canionD->getCanionDefensivo()->getPosicion()->getX();
    float xO=canionO->getCanionOfensivo()->getPosicion()->getX();
    return abs(xO-xD);
}

void MainWindow::mostrarinfo(Bala bala)
{

}



bool MainWindow::impacto(Posicion *canionxy, Posicion *balaxy)
{
    cout<<"xcanion "<<canionxy->getX()<<endl;
    cout<<"ycanion "<<canionxy->getY()<<endl;
    float d=calcularD();
    float r = pow(pow(balaxy->getX()-canionxy->getX(),2)+pow(balaxy->getY()-canionxy->getY(),2),0.5);
    if(!start){
        cout<<"xbala "<<balaxy->getX()<<endl;
        cout<<"ybala "<<balaxy->getY()<<endl;
        cout <<"d"<<d<<endl;
        cout <<"r"<<r<<endl;

    }
        if(r<=(0.05*d)){
        return true;
    }else{
        return false;
    }
}

void MainWindow::generar_disparoO()
{
    if(anguloIO<90 and nCaso==1){
        cout<<"iniciar"<<endl;
        timer1->start(dt);

        float d=calcularD();
        balaO=canionO->getCanionOfensivo()->Disparo(10);
        float xbala=balaO->getPosicion()->getX();
        float rcanion=canionO->getRadio();
        float ybala=balaO->getPosicion()->getY();
        cout <<"actualizacionX"<<xbala-rcanion<<endl;
        cout <<"actualizacionT"<<ybala<<endl;
        balaO->Actualizar(xbala-rcanion,ybala);
        impactoO=new impactograf(0.05*d,new Posicion(xbala-rcanion,ybala));
        scene->addItem(impactoO);
        scene->addItem(balaO);
        anguloIO+=anguloInvO;
        cont=5000;
    }
}

void MainWindow::Caso1()
{
    balaO->getBala()->Movimiento(anguloIO);
    //cout<<"caso1"<<endl;
    float xbala=balaO->getBala()->getPos()->getX();
    float rcanion=canionO->getRadio();
    float ybala=-balaO->getBala()->getPos()->getY();
    //cout << "balaox "<<xbala<<endl;

    //cout << "balaoy "<<ybala<<endl;
    float newposx=xbala-rcanion+canionO->getCanionOfensivo()->getPosicion()->getX();
    float newposy=ybala+canionO->getCanionOfensivo()->getPosicion()->getY();
    impactoO->Actualizar(newposx,newposy);
    balaO->Actualizar(newposx,newposy);

    if(cont%30==0){
        Movgraf *mov=new Movgraf(balaO->getBala()->getRadio()/7,new Posicion(newposx,newposy));
        scene->addItem(mov);
    }
    bool imp=impacto(canionD->getCanionDefensivo()->getPosicion(),
                     new Posicion(newposx,newposy));
    cout<<"imp "<<imp<<endl;
    if(imp){

        timer1->stop();
        generar_disparoO();
        cont=0;
    }else{

        if(cont==0){

            timer1->stop();
            generar_disparoO();
            cout<<"parar"<<endl;
        }else{
            cont--;
        }
    }
    if(cont==0 and start==false){
        timer1->stop();
    }
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

void MainWindow::on_iniciarCaso_clicked()
{
    generar_disparoO();
    if(start){
        cont=0;
        start=false;
    }else{
        cont=5000;
        start=true;
    }
    int xO=ui->posxO->value();
    int yO=ui->alturaO->value();
    int xD=ui->posxD->value();
    int yD=ui->alturaD->value();
    anguloIO=ui->anguloIO->value();
    anguloID=ui->anguloID->value();
    anguloInvO=ui->intervaloO->value();
    anguloInvD=ui->intervaloD->value();
    velInO=ui->VelIO->value();
    velInD=ui->VelId->value();

    scene = new QGraphicsScene(this);
    scene->setSceneRect(-500,-200,1000,400);

    ui->campo->setScene(scene);
    //ui->centralwidget->adjustSize();


    this->canionD=new Caniongraf(30,velInD,new Posicion(xD,yD),true);
    this->canionD->setEscala(0.5);

    this->canionO=new Caniongraf(30,velInO,new Posicion(xO,yO),false);
    this->canionO->setEscala(0.5);

    scene->addItem(this->canionD);
    scene->addItem(this->canionO);

}

void MainWindow::on_listaCasos_currentIndexChanged(int index)
{
    nCaso=index;

}
