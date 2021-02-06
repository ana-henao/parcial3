#include "impactograf.h"


impactograf::impactograf(float r, Posicion *pos)
{
    this->R=r;
    this->pos=pos;
    setPos(pos->getX(),pos->getY());
}

QRectF impactograf::boundingRect() const
{
   return QRectF(-1*escala*R,-1*escala*R,2*escala*R,2*escala*R);
}

void impactograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

void impactograf::Actualizar(float x, float y)
{
     setPos(x,y);
}

void impactograf::setEscala(float e)
{
    this->escala=e;
}

Posicion *impactograf::getPosicion()
{
    return pos;
}
