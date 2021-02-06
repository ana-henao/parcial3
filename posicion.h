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
    void setX(float x);
    void setY(float y);
};

#endif // POSICION_H
