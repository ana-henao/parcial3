#ifndef BALAGRAF_H
#define BALAGRAF_H
#include "bala.h"
#include <QGraphicsItem>
#include "movgraf.h"
#include <QPainter>


class Balagraf: public QGraphicsItem
{
private:
    float R;
    float escala;
    Bala *bala;

public:
    Balagraf(float R, Posicion *pos, float Vo);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    Bala* getBala();
    Movgraf Actualizar(float x, float y);
    void setEscala(float e);

};

#endif // BALAGRAF_H
