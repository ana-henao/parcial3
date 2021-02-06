#include "canion.h"
#include "iostream"


using namespace std;

Canion::Canion(float vo, Posicion* pos)
{
   this->vo=vo;
   this->pos=pos;
}

Balagraf* Canion::Disparo(float R)
{
    //cout<< "Xcanion" << this->pos->getX()<<endl;
    //cout<< "Ycanion" << this->pos->getY()<<endl;
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

void Canion::setVo(float Vo)
{
    this->vo=Vo;
}

float Canion::getVo()
{
    return this->vo;
}
