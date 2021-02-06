#include "caniondefensivo.h"
#include "iostream"

using namespace std;

CanionDefensivo::CanionDefensivo(float vo, Posicion* pos): Canion(vo, pos){


}

QVector<float> CanionDefensivo::Predecir( Posicion * posO)
{
    bool imp=false;
    float x=posO->getX();
    float y=posO->getY();

    float xO=posO->getX();
    float xD=this->pos->getX();
    float d= abs(xO-xD);


    int flag=0;
    float Vxo,Vy0;
    float Vfin=0, anguloFin=0;
    int t = 0;
    float angle = 0;
    for(float V0o = 0.1; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((angle)*pi/180);
            Vy0 = V0o*sin((angle)*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = posO->getY() + Vy0*t -(0.5*G*t*t);

                float r = pow(pow(this->pos->getX()-x,2)+pow(this->pos->getY()-y,2),0.5);
                if(r < 0.05*d){
                    if(y<0) y=0;
                    Vfin=V0o;
                    anguloFin=angle;
                    imp=true;
                    flag += 1;
                    V0o+=25;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag==1) break;

        }
        if(flag==1) break;
    }


    QVector<float> datos;
    datos.append(Vfin);
    datos.append(anguloFin);
    return datos;

}

