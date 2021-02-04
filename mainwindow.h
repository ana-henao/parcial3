#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "caniongraf.h"



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
    void Caso1();
    void Caso2();
    void Caso3();
    void Caso4();
    void Caso5();
    bool impacto(Posicion canionxy, Posicion balaxy);



private:
    QGraphicsScene scene_batalla;

    QTimer *timer;
    QGraphicsScene *scene;
    float dt;
    Caniongraf *canionD;
    Caniongraf *canionO;


    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
