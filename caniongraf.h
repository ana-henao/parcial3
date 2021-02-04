#ifndef CANIONGRAF_H
#define CANIONGRAF_H

#include "posicion.h"
#include "movgraf.h"
#include <QGraphicsItem>
#include "caniondefensivo.h"
#include "canionofensivo.h"
#include "QPainter"



class Caniongraf: public QGraphicsItem
{
private:

    CanionDefensivo *def;
    CanionOfensivo *of;
    float radio;
    float escala;

public:
    Caniongraf(float r, float vo, Posicion* pos, bool def);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    CanionDefensivo* getCanionDefensivo();
    CanionOfensivo* getCanionOfensivo();
    Movgraf Actualizar(float x, float y);
    void setEscala(float e);
};

#endif // CANIONGRAF_H
