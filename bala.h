#ifndef BALA_H
#define BALA_H
#include "posicion.h"
const double pi=3.141617;
const double G=9.8;
#include <math.h>
#include <cmath>


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
    float t=0;

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
