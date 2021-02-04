#include "bala.h"

Bala::Bala(float R, Posicion *pos, float vo)
{
    this->radio=R;
    this->vo=vo;


}

void Bala::Movimiento(float a)
{

}

Posicion* Bala::getPos()
{
    return this->pos;
}

float Bala::getVx()
{
    return vx;
}

float Bala::getVy()
{
    return vy;
}

float Bala::getAx()
{
    return ax;
}

float Bala::getAy()
{
    return ax;
}

float Bala::getRadio()
{
    return radio;
}

float Bala::getRadio_im()
{
    return radio_im;
}

float Bala::getAngulo()
{
    return angulo;
}

