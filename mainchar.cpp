
#include "mainchar.h"

mainchar::mainchar() : Character(0, 0)
{
    //Obtain QPixmap full
    QPixmap imagen;
    imagen.load("://Recursos/Practica5_sprites.png");
    *full = imagen.copy(0, 0, ancho_mainchar*7, alto_mainchar*3);
}

mainchar::~mainchar()
{

}

void mainchar::Dead_Animation()
{

}

void mainchar::keyPressEvent(QKeyEvent *event)
{
    //Movement


    //Bomba (para bailar esto es una Bomba)
    if(event->key()==Qt::Key_B){
        //Bomba poner :)
    }
    else{
        //No Bomba poner :(
    }
}

void mainchar::keyReleaseEvent(QKeyEvent *event)
{

}

