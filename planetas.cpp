#include "planetas.h"
#include <fstream>


float Planetas::getposx()
{
    return Pposx;
}

float Planetas::getposy()
{
    return Pposy;
}


float Planetas::getvelx()
{
    return Pvelx;
}

float Planetas::getvely()
{
    return Pvely;
}


float Planetas::getmasa()
{
    return Pmasa;
}


Planetas::Planetas()
{

}
QRectF Planetas::boundingRect() const
{
    return QRectF(-Pradio,-Pradio,2*Pradio,2*Pradio);
}
void Planetas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/planeta.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}


/*
void Planetas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::cyan);
    painter->drawEllipse(boundingRect());
}
*/

Planetas::Planetas(float x, float y, float vx, float vy, float m, float r)
 {
      Pposx =x;
      Pposy = y;
      Pvelx = vx;
      Pvely =vy;
      Pmasa=m;
      Pradio =r;
      Velx=0;
      Vely=0;
      Acelx=0;
      Acely=0;


}

float Planetas::CalcularAcelx(Planetas *A)
{
    float dist,ang;

    dist=sqrt( pow(A->getposx()-getposx(),2)+ pow( A->getposy()-getposy(),2));
    ang= atan2(( A->getposy()-getposy()) , A->getposx()-getposx());
    Acelx +=(((c_gra * A->getmasa()) / pow(dist,2))*cos(ang) );

 return Acelx;

}

float Planetas::CalcularAcely(Planetas *A)
{
    float dist,ang;

    dist=sqrt( pow( A->getposx()-getposx(),2)+ pow( A->getposy()-getposy(),2));
    ang= atan2(( A->getposy()-getposy()) , A->getposx()-getposx());
    Acely += (((c_gra * A->getmasa()) / pow(dist,2))*sin(ang));

    return Acely;
}

float Planetas::CalcularVelx()
{
 Velx= getvelx() + (Acelx* g);
         return Velx;
}

float Planetas::CalcularVely()
{
    Vely= getvely() + (Acely* g);
            return Vely;

}

float Planetas::getPosx()
{
    Posx=getposx()+(getvelx() * g) + ((Acelx* pow(g,2)/2));
     return Posx;

}

float Planetas::getPosy()
{
    Posy=getposy()+(getvely() * g) + ((Acely* pow(g,2)/2));
     return Posy;

}



void Planetas::ModValor()
{
    Pposx=Posx;
    Pposy=Posy;
    Pvelx=Velx;
    Pvely=Vely;
    Acelx=0;
    Acely=0;

}

void Planetas::mover()
{

    //qDebug()<<"Posiciones sin escalar  Posx= "<<Posx << "  Posy= "<<Posy<<endl;
    setPos(Posx*es,-Posy*es);
    //qDebug()<<"Posiciones escaladas  Posx= "<<Posx*es << "  Posy= "<<Posy*es<<endl;
}
