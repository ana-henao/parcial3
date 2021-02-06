#ifndef BALAGRAF_H
#define BALAGRAF_H
#include "bala.h"
#include <QGraphicsItem>
#include <QPainter>


class Balagraf: public QGraphicsItem
{
private:
    float R;
    float escala=0.8;
    Bala *bala;
    Posicion *pos;

public:
    Balagraf(float R, Posicion *pos, float Vo);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    Bala* getBala();
    void Actualizar(float x, float y);
    void setEscala(float e);
    Posicion* getPosicion();

};

#endif // BALAGRAF_H
