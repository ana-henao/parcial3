#include "bala.h"
#include "iostream"

using namespace std;

Bala::Bala(float R, Posicion *pos, float vo)
{
    this->radio=R;
    this->vo=vo;
    this->pos=pos;


}

void Bala::Movimiento(float a)
{
    this->angulo=a;
    this->t+=0.0001;
    vx = vo*cos((a)*pi/180);
    vy = vo*sin((a)*pi/180);
    //cout << "vx" << vx<<endl;
    //cout << "vy" << vy<<endl;
    float x=this->pos->getX() + vx*this->t;
    //cout << "x" << x<<endl;


    this->pos->setX(x);
    //cout << "pos x" << this->pos->getX()<<endl;
    float y=this->pos->getY() + vy*this->t -(0.5*G*this->t*this->t);
    //cout << "y" << y<<endl;
    this->pos->setY(y);
    //cout << "pos y" << this->pos->getY()<<endl;
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

