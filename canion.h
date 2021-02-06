#ifndef CANION_H
#define CANION_H
#include "balagraf.h"


class Canion
{
private:
    Posicion *pos;
    float SegInf;
    float vo;

public:
    Canion(float vo, Posicion* pos);
    Balagraf* Disparo(float R);
    bool infiltrado(float t);
    void setSegInfiltrado(float t);
    Posicion* getPosicion();
    void setVo(float Vo);
    float getVo();
};

#endif // CANION_H
