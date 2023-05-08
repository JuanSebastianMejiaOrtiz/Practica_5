
#include "mainchar.h"

mainchar::mainchar()
{
    //Inicializar variables
    movement_input = new char;
    *movement_input = 'n';

    //Obtain Sprite Main Character
    QPixmap imagen;
    imagen.load("://Recursos/Practica5_sprites.png");
    *full = imagen.copy(x,y,ancho,alto);
    setPos(0,0);
    //setPixmap(ImgMainChar);
}

mainchar::~mainchar()
{
    delete movement_input;
}

void mainchar::keyPressEvent(QKeyEvent *event)
{
    //Movement
    if(event->key()==Qt::Key_W){
        *movement_input = 'u';
    }
    else if(event->key()==Qt::Key_S){
        *movement_input = 'd';
    }
    else if(event->key()==Qt::Key_A){
        *movement_input = 'l';
    }
    else if(event->key()==Qt::Key_D){
        *movement_input = 'r';
    }
    else{
        *movement_input = 'n';
    }

    //Bomba (para bailar esto es una Bomba)
    if(event->key()==Qt::Key_B){
        //Bomba poner :)
    }
    else{
        //No Bomba poner :(
    }
}

