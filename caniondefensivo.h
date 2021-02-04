#ifndef CANIONDEFENSIVO_H
#define CANIONDEFENSIVO_H
#include "posicion.h"
#include "canion.h"

class CanionDefensivo: public Canion
{

public:
    CanionDefensivo(float vo, Posicion* pos);;
    void Predecir(float vo, float angulo);


};

#endif // CANIONDEFENSIVO_H
