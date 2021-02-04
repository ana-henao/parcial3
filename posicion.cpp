#include "posicion.h"


Posicion::Posicion(float x, float y)
{
    this->x=x;
    this->y=y;
}

float Posicion::getX()
{
    return x;
}

float Posicion::getY()
{
    return y;
}

void Posicion::setX(float x)
{
    this->x=x;
}

void Posicion::setY(float y)
{
    this->y=y;
}
