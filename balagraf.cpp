#include "balagraf.h"


Balagraf::Balagraf(float R, Posicion *pos, float Vo)
{
    this->bala=new Bala(R,pos,Vo);
    setPos(pos->getX(),pos->getY());

}

void Balagraf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
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

Movgraf Balagraf::Actualizar(float x, float y)
{
    setPos(x,y);
}

void Balagraf::setEscala(float e)
{
    this->escala=e;
}

