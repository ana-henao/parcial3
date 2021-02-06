#ifndef MOVGRAF_H
#define MOVGRAF_H
#include "posicion.h"
#include <QColor>
#include <QGraphicsItem>
#include "QPainter"


class Movgraf: public QGraphicsItem
{
private:
    float radio;
    float escala=0.8;
    Posicion *pos;

public:
    Movgraf(float r, Posicion *pos);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    QColor* getColorRandom();
    void setEscala(float e);
};

#endif // MOVGRAF_H
