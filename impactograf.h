#ifndef IMPACTOGRAF_H
#define IMPACTOGRAF_H
#include <QGraphicsItem>
#include <QPainter>
#include "posicion.h"

class impactograf: public QGraphicsItem

{
private:
    float R;
    float escala=0.5;
    Posicion *pos;

public:
    impactograf(float r, Posicion* pos);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    void Actualizar(float x, float y);
    void setEscala(float e);
    Posicion* getPosicion();
};

#endif // IMPACTOGRAF_H
