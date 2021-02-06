#include "movgraf.h"


Movgraf::Movgraf(float r, Posicion *pos)
{
    this->radio=r;
    this->pos=pos;
    setPos(this->pos->getX(),this->pos->getY());
}

QRectF Movgraf::boundingRect() const
{
    return QRectF(-1*escala*this->radio,-1*escala*this->radio,2*this->radio,2*escala*this->radio);
}

void Movgraf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::darkCyan);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(boundingRect());

}

QColor* Movgraf::getColorRandom()
{
    int r=qrand() % 255;
    int g=qrand() % 255;
    int b=qrand() % 255;

    return new QColor(r,g,b,255);
}

void Movgraf::setEscala(float e)
{
    this->escala=e;
}
