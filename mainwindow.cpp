#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cronometro=new QTimer(this);      //crea el timer
    scene=new QGraphicsScene(this);  // crea la escena
    ui->pushButton->show();
    scene->setSceneRect(-200,-200,400,400);

    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/fondo")));

    ui->graphicsView->setScene(scene);
    ui->pushButton->show();
    ui->graphicsView->resize(scene->width()+500,scene->height()+250);  //Modificar la dimensión del scene
    this->resize(ui->graphicsView->width()+2000,ui->graphicsView->height()+100);
    //Movimiento en el sistema 2 (4 planetas)
    Cuerpos[0]=new Planetas(0,0,0,0,50000,60);  //Pinix,PiniY,VeliniX,VeliniY,Masa,radio
    Cuerpos[1]=new Planetas(-5000,0,0,-2,70,30);
    Cuerpos[2]=new Planetas(5000,0,0,2,70,30);
    Cuerpos[3]=new Planetas(0,5000,-2,0,70,30);
    /*
    //Movimiento en el sistema 1  (3 planetas)
    Cuerpos[0]=new Planetas(0.-7000,2,0,70,15);
    Cuerpos[1]=new Planetas(0,0,0,0,70000,30);
    Cuerpos[2]=new Planetas(4000,5000,-1.6,1.2,25,10);
    */
     scene->addItem(Cuerpos[0]);
     scene->addItem(Cuerpos[1]);
     scene->addItem(Cuerpos[2]);
     scene->addItem(Cuerpos[3]);
     connect(cronometro,SIGNAL(timeout()),this,SLOT(update()));
     //cronometro->start(20);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update()
{
    for(int j=0; j<4; j++)
       {
           for(int k=0; k<4; k++)
           {
               if(j != k){
                   Cuerpos[j]->CalcularAcelx(Cuerpos[k]);
                   Cuerpos[j]->CalcularAcely(Cuerpos[k]);
                   Cuerpos[j]->getPosx();
                   Cuerpos[j]->getPosy();
                   Cuerpos[j]->CalcularVelx();
                   Cuerpos[j]->CalcularVely();
                   Cuerpos[j]->mover();
               }
           }

           Cuerpos[j]->ModValor();

       }

   }


void MainWindow::on_pushButton_clicked()
{


    cronometro->start(0.5);

}
