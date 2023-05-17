
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
    if (event->key() == Qt::Key_W){
        Set_Direction('u');
        Move();
    }
    else if (event->key() == Qt::Key_S){
        Set_Direction('d');
        Move();
    }
    else if (event->key() == Qt::Key_A){
        Set_Direction('l');
        Move();
    }
    else if (event->key() == Qt::Key_D){
        Set_Direction('r');
        Move();
    }

    //Bomba (para bailar esto es una)
    if(event->key() == Qt::Key_B){
        //Bomba poner :)
    }
    else{
        //No Bomba poner :(
    }
}

