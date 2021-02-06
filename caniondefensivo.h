#ifndef CANIONDEFENSIVO_H
#define CANIONDEFENSIVO_H
#include "posicion.h"
#include <QVector>
#include "canion.h"

class CanionDefensivo: public Canion
{

public:
    CanionDefensivo(float vo, Posicion* pos);;
    QVector<float> Predecir( Posicion * posO);


};

#endif // CANIONDEFENSIVO_H
