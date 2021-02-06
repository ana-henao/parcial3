#include "caniongraf.h"


Caniongraf::Caniongraf(float r, float vo, Posicion* pos, bool def)
{
    this->radio=r;
    if(def){
        this->def=new CanionDefensivo(vo,pos);
        this->of=NULL;
    }else{
        this->of=new CanionOfensivo(vo,pos);
        this->def=NULL;
    }
    setPos(pos->getX()*escala,pos->getY()*escala);

}

QRectF Caniongraf::boundingRect() const
{
    float x=0;
    float y=0;
    if(this->of==NULL){
        x=this->def->getPosicion()->getX();
        y=this->def->getPosicion()->getY();
    }else{
        x=this->of->getPosicion()->getX();
        y=this->of->getPosicion()->getY();
    }
    return QRectF(x*escala,y*escala,radio,radio);
}


void Caniongraf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}

CanionDefensivo *Caniongraf::getCanionDefensivo()
{
    return def;
}

CanionOfensivo *Caniongraf::getCanionOfensivo()
{
    return of;
}


Movgraf Caniongraf::Actualizar(float x, float y)
{
    setPos(x*escala,y*escala);
}

void Caniongraf::setEscala(float e)
{
    this->escala=e;
}

float Caniongraf::getRadio()
{
    return this->radio;
}









