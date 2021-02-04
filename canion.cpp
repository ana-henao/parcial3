#include "canion.h"


Canion::Canion(float vo, Posicion* pos)
{
   this->vo=vo;
   this->pos=pos;
}

Balagraf* Canion::Disparo(float R)
{
    Balagraf *bala=new Balagraf(R,this->pos,this->vo);
    return bala;
}

bool Canion::infiltrado(float t)
{

}

void Canion::setSegInfiltrado(float t)
{
    this->SegInf=t;
}

Posicion *Canion::getPosicion()
{
    return this->pos;
}
