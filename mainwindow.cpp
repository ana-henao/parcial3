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
    timer2->stop();
    timer3->stop();
//    timer4->stop();
//    timer5->stop();

    connect(timer1,SIGNAL(timeout()),this,SLOT(Caso1()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(Caso2()));
    connect(timer3,SIGNAL(timeout()),this,SLOT(Caso3()));
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
    //cout<<"xcanion "<<canionxy->getX()<<endl;
    //cout<<"ycanion "<<canionxy->getY()<<endl;
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
    if(angulo<=90 and nCaso==1){
        cout<<"iniciar"<<endl;
        float d=calcularD();
        balaO=canionO->getCanionOfensivo()->Disparo(5);
        float xbala=balaO->getPosicion()->getX();
        float rcanion=canionO->getRadio();
        float ybala=balaO->getPosicion()->getY();
       // cout <<"actualizacionX"<<xbala-rcanion<<endl;
       // cout <<"actualizacionT"<<ybala<<endl;
        balaO->Actualizar(xbala-rcanion,ybala);
        impactoO=new impactograf(0.05*d,new Posicion(xbala-rcanion,ybala));
        scene->addItem(impactoO);
        scene->addItem(balaO);
        timer1->start(dt);
        cont=7000;
    }

    if(angulo>=90  and angulo<=180 and nCaso==2){
        cout<<"iniciar"<<endl;
        float d=calcularD();
        balaD=canionD->getCanionDefensivo()->Disparo(5);
        float xbala=balaD->getPosicion()->getX();
        float rcanion=canionD->getRadio();
        float ybala=balaD->getPosicion()->getY();
       // cout <<"actualizacionX"<<xbala-rcanion<<endl;
       // cout <<"actualizacionT"<<ybala<<endl;
        balaD->Actualizar(xbala+rcanion,ybala);
        impactoD=new impactograf(0.025*d,new Posicion(xbala+rcanion,ybala));
        scene->addItem(impactoD);
        scene->addItem(balaD);
        timer2->start(dt);
        cont=7000;
    }
}

Balagraf* MainWindow::cambioAngulo(float Vo, bool ataque, Posicion * pos)
{
    bool imp=false;
    Balagraf *bala_;
    Caniongraf * canion_;
    float max_=0;

    if (ataque){
        max_=90;
        canion_=canionO;
        canion_->getCanionOfensivo()->setVo(Vo);

        bala_=canion_->getCanionOfensivo()->Disparo(10);

        if(nImpO<10){
            for(int i=anguloIO;i<max_;i+=anguloInvO){
                //cout<<"c angulo: "<<i<<endl;
                float ycanion=canion_->getCanionOfensivo()->getPosicion()->getY();
                float ybala=0;
                do{
                     bala_->getBala()->Movimiento(i);
                     float xbala=bala_->getBala()->getPos()->getX();
                     float rcanion=canion_->getRadio();
                     float newposx=0;
                     float newposy=0;
                     ybala=-bala_->getBala()->getPos()->getY();

                     if(ataque){
                         newposx=xbala-rcanion+canion_->getCanionOfensivo()->getPosicion()->getX();
                         newposy=ybala+canion_->getCanionOfensivo()->getPosicion()->getY();

                         float xcanionD=pos->getX();
                         float ycanionD=pos->getY();
                         imp=impacto(new Posicion(xcanionD,ycanionD),
                                          new Posicion(newposx,newposy));


                         if(imp){
                             canionO=canion_;
                             angulo=i;

                             break;
                         }

                     }


                }while(ybala<ycanion );

                //cout<<"ybala: "<<ybala<<endl;
                //cout<<"ycanion: "<<ycanion<<endl;

                if (imp){
                    //imp=false;
                    break;
                }
            }

            if(!imp){
                 velInO+=velInvO;
                cout<<"imp"<<nImpO<<endl;
                 ui->intervaloO->setValue(angulo);
                 ui->CambioVO->setValue(velInO);
                 cambioAngulo(velInO,ataque,pos);
            }else{

                cout<<"imp"<<nImpO<<endl;
                nImpO++;
                generar_disparoO();

            }

        }
    }else{
        max_=90;

        canion_=canionD;
        canion_->getCanionDefensivo()->setVo(Vo);

        bala_=canion_->getCanionDefensivo()->Disparo(10);
        angulo=anguloID;
        if(nImpD<10){
            for(int i=anguloID;i>max_;i-=anguloInvD){
                //cout<<"Def angulo: "<<i<<endl;
                float ycanion=canion_->getCanionDefensivo()->getPosicion()->getY();
                float ybala=0;
                do{
                     bala_->getBala()->Movimiento(i);
                     float xbala=bala_->getBala()->getPos()->getX();
                     float rcanion=canion_->getRadio();
                     float newposx=0;
                     float newposy=0;
                     ybala=-bala_->getBala()->getPos()->getY();

                     if(!ataque){
                         newposx=xbala-rcanion+canion_->getCanionDefensivo()->getPosicion()->getX();
                         //cout<<"xpos: "<<newposx<<endl;
                         newposy=ybala+canion_->getCanionDefensivo()->getPosicion()->getY();

                         float xcanionO=pos->getX();
                         float ycanionO=pos->getY();
                         imp=impacto(new Posicion(xcanionO,ycanionO),
                                          new Posicion(newposx,newposy));


                         if(imp){
                             canionD=canion_;
                             angulo=i;

                             break;
                         }

                     }


                }while(ybala<ycanion );

                //cout<<"ybala: "<<ybala<<endl;
                //cout<<"ycanion: "<<ycanion<<endl;

                if (imp){
                    //imp=false;
                    break;
                }
            }

            if(!imp){
                 velInD+=velInvD;
                // cout<<"c angulo !imp: "<<angulo<<endl;
                //cout<<"vel"<<velInD<<endl;
                // ui->intervaloD->setValue(angulo);
                // ui->CambioVD->setValue(velInD);
                 cambioAngulo(velInD,false,pos);
            }else{
//                cout<<"c angulo: "<<angulo<<endl;
//                cout<<"Vo canion: "<<canionD->getCanionDefensivo()->getVo()<<endl;
//                cout<<"imp"<<nImpD<<endl;
                nImpD++;
                generar_disparoO();

            }

        }
    }




    return bala_;
}



void MainWindow::Caso1()
{

    balaO->getBala()->Movimiento(angulo);
    //cout<<"caso1"<<endl;
    float xbala=balaO->getBala()->getPos()->getX();
    float rcanion=canionO->getRadio();
    float ybala=-balaO->getBala()->getPos()->getY();
    //cout << "balaox "<<xbala<<endl;

    //cout << "balaoy "<<ybala<<endl;
    float newposx=xbala-(rcanion)+canionO->getCanionOfensivo()->getPosicion()->getX();
    float newposy=ybala+canionO->getCanionOfensivo()->getPosicion()->getY();
    impactoO->Actualizar(newposx,newposy);
    balaO->Actualizar(newposx,newposy);

    if(cont%30==0){
        Movgraf *mov=new Movgraf(balaO->getBala()->getRadio()/7,new Posicion(newposx,newposy));
        scene->addItem(mov);
    }

    //cout<<"c angulo: "<<angulo<<endl;
    //cout<<"Vo canion: "<<canionO->getCanionOfensivo()->getVo()<<endl;

    if(cont==0){

            timer1->stop();
            velInO+=velInvO;
            cambioAngulo(velInO,true, canionD->getCanionDefensivo()->getPosicion());
            cout<<"parar"<<endl;
    }else{
            cont--;
    }


}

void MainWindow::Caso2()
{
    balaD->getBala()->Movimiento(angulo);
    //cout<<"caso1"<<endl;
    float xbala=balaD->getBala()->getPos()->getX();
    float rcanion=canionD->getRadio();
    float ybala=-balaD->getBala()->getPos()->getY();
    //cout << "balaox "<<xbala<<endl;

    //cout << "balaoy "<<ybala<<endl;
    float newposx=xbala+(2*rcanion)+canionD->getCanionDefensivo()->getPosicion()->getX();
    float newposy=ybala+canionD->getCanionDefensivo()->getPosicion()->getY();
    impactoD->Actualizar(newposx,newposy);
    balaD->Actualizar(newposx,newposy);

    if(cont%30==0){
        Movgraf *mov=new Movgraf(balaD->getBala()->getRadio()/7,new Posicion(newposx,newposy));
        scene->addItem(mov);
    }

    //cout<<"c angulo: "<<angulo<<endl;
    //cout<<"Vo canion: "<<canionD->getCanionDefensivo()->getVo()<<endl;

    if(cont==0){

            timer2->stop();
            velInD+=velInvD;
            cambioAngulo(velInD,false, canionO->getCanionOfensivo()->getPosicion());
            cout<<"parar"<<endl;
    }else{
            cont--;
    }
}

void MainWindow::Caso3()
{    

    canionD->getCanionDefensivo()->setSegInfiltrado(2);

    tO+=dt;

    if( tO==2){
        canionO->getCanionOfensivo()->setVo(datos[0]);
        balaO=canionO->getCanionOfensivo()->Disparo(5);

    }

    if(tO>2){
        balaO->getBala()->Movimiento(datos[1]);
        //cout<<"caso1"<<endl;
        float xbala=balaO->getBala()->getPos()->getX();
        float rcanion=canionO->getRadio();
        float ybala=-balaO->getBala()->getPos()->getY();
        //cout << "balaox "<<xbala<<endl;

        //cout << "balaoy "<<ybala<<endl;
        float newposx=xbala-(rcanion)+canionO->getCanionOfensivo()->getPosicion()->getX();
        float newposy=ybala+canionO->getCanionOfensivo()->getPosicion()->getY();
        impactoO->Actualizar(newposx,newposy);
        balaO->Actualizar(newposx,newposy);

        if(cont%30==0){
            Movgraf *mov=new Movgraf(balaO->getBala()->getRadio()/7,new Posicion(newposx,newposy));
            scene->addItem(mov);
        }

        //cout<<"c angulo: "<<angulo<<endl;
        //cout<<"Vo canion: "<<canionO->getCanionOfensivo()->getVo()<<endl;

        if(cont==0){

                timer3->stop();
                //velInD+=velInvD;
                //cambioAngulo(velInD,false, balaO->getPosicion());
                cout<<"parar"<<endl;
        }else{
                cont--;
        }

    }

}

void MainWindow::Caso4()
{

}

void MainWindow::Caso5()
{

}

void MainWindow::on_iniciarCaso_clicked()
{

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
    velInvO=ui->CambioVO->value();
    velInvD=ui->CambioVD->value();

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

    if(nCaso==1){
        cambioAngulo(velInO,true, canionD->getCanionDefensivo()->getPosicion());
    }else if (nCaso==2){
         cambioAngulo(velInD,false, canionO->getCanionOfensivo()->getPosicion());
    }else if (nCaso==3){


           datos=canionD->getCanionDefensivo()->Predecir(canionO->getCanionOfensivo()->getPosicion());



       timer3->start(dt);
   }

}

void MainWindow::on_listaCasos_currentIndexChanged(int index)
{
    nCaso=index;

}
