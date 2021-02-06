#include "balagraf.h"
#include "iostream"

using namespace std;


Balagraf::Balagraf(float R, Posicion *pos, float Vo)
{
    //cout<< "Xbalagraf" << pos->getX()<<endl;
    //cout<< "Ybalagraf" << pos->getY()<<endl;
    this->bala=new Bala(R,new Posicion(0,0),Vo);
    setPos(pos->getX()*escala,pos->getY()*escala);
    this->pos=pos;


}

void Balagraf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

QRectF Balagraf::boundingRect() const
{
    return QRectF(-1*escala*bala->getRadio(),-1*escala*bala->getRadio(),2*escala*bala->getRadio(),2*escala*bala->getRadio());
}

Bala* Balagraf::getBala()
{
    return bala;
}

void Balagraf::Actualizar(float x, float y)
{

    //this->pos->setX(x);
    //this->pos->setY(y);
    setPos(x*escala,y*escala);

}

void Balagraf::setEscala(float e)
{
    this->escala=e;
}

Posicion *Balagraf::getPosicion()
{
    return pos;
}

