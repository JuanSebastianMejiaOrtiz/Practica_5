
#include "mainchar.h"

mainchar::mainchar()
{
    //Inicializar variables
    mc = new Character(pos_x_initial, pos_y_initial);

    //Obtain QPixmap full
    QPixmap imagen;
    imagen.load("://Recursos/Practica5_sprites.png");
    *(mc->full) = imagen.copy(0, 0, ancho_mainchar*7, alto_mainchar*3);
}

mainchar::~mainchar()
{
    delete mc;
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

