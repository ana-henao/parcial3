#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "movgraf.h"
#include "caniongraf.h"
#include "QTimer"



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

public slots:
    void Caso1();
    void Caso2();
    void Caso3();
    void Caso4();
    void Caso5();
    //void Actualizacion();

private slots:
    void on_iniciarCaso_clicked();

    void on_parar_clicked();

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
    bool start=true;
    int cont=1000;
    float anguloO=5;


    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
