#ifndef PLANETAS_H
#define PLANETAS_H
#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#include <QDebug>


#define c_gra 1
#define g  1
#define es 0.04

class Planetas : public QGraphicsItem
{
private:
    float Pposx,Pposy,Pvelx,Pvely,Pmasa,Pradio;

public:
     float posx, posy,velx,vely, masa,Posx,Posy,Velx,Vely,Acelx,Acely;
    Planetas();
    Planetas(float x, float y, float vx, float vy, float m, float r);
    float CalcularAcelx(Planetas *A);
    float CalcularAcely(Planetas *A);
    float CalcularVelx();
    float CalcularVely();
    void Modificar();
    void ModValor();
    void  mover();
    float getposx() ;
    float getposy() ;
    float getvelx() ;
    float getvely() ;
    float getmasa() ;
    float getPosx();
    float getPosy();
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PLANETAS_H
