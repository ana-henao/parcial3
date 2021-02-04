#ifndef BALA_H
#define BALA_H
#include "posicion.h"


class Bala
{
private:
    float radio;
    float radio_im;
    float vx;
    float vy;
    float ax;
    float ay;
    Posicion *pos;
    float angulo;
    float vo;

public:
    Bala(float R, Posicion *pos, float vo);
    void Movimiento(float a);
    Posicion* getPos();
    float getVx();
    float getVy();
    float getAx();
    float getAy();
    float getRadio();
    float getRadio_im();
    float getAngulo();

};

#endif // BALA_H
