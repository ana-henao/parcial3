#ifndef CANIONOFENSIVO_H
#define CANIONOFENSIVO_H
#include "posicion.h"
#include "canion.h"


class CanionOfensivo: public Canion
{
private:


public:
    CanionOfensivo(float vo, Posicion* pos);;
    void Neutralizar (float vo, float angulo);

};

#endif // CANIONOFENSIVO_H
