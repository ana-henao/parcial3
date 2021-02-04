#ifndef POSICION_H
#define POSICION_H


class Posicion
{
private:
    float x;
    float y;
public:
    Posicion(float x, float y);
    float getX();
    float getY();
    void setX(float y);
    void setY(float x);
};

#endif // POSICION_H
