#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "movgraf.h"
#include "caniongraf.h"
#include "QTimer"
#include "impactograf.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    float calcularD();
    void mostrarinfo(Bala bala);
    bool impacto(Posicion *canionxy, Posicion *balaxy);
    void generar_disparoO();
    Balagraf* cambioAngulo(float Vo, bool ataque);


public slots:
    void Caso1();
    void Caso2();
    void Caso3();
    void Caso4();
    void Caso5();
    //void Actualizacion();

private slots:
    void on_iniciarCaso_clicked();
    void on_listaCasos_currentIndexChanged(int index);

private:
    QGraphicsScene scene_batalla;

    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QTimer *timer5;
    QGraphicsScene *scene;
    float dt=0.1;
    Caniongraf *canionD;
    Caniongraf *canionO;
    Balagraf *balaD;
    Balagraf *balaO;
    impactograf *impactoD;
    impactograf *impactoO;
    bool start=false;
    int cont=1000;
    float anguloIO=5;
    float anguloID=5;
    float angulo=0;
    float anguloInvO=5;
    float anguloInvD=5;
    float velInO=0.5;
    float velInD=0.5;
    float velInvO=0.5;
    float velInvD=0.5;
    int nCaso=0;
    int nImpO=0;
    int nImpD=0;


    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
