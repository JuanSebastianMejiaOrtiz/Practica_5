
#include "mainchar.h"

mainchar::mainchar(int x, int y, int ancho, int alto)
{
    //Inicializar variables
    movement_input = new char;
    *movement_input = 'n';
    ImgMainChar = new QPixmap;
    Se_Mueve = new bool;
    *Se_Mueve = 1;

    //Obtain Sprite Main Character
    QPixmap imagen;
    imagen.load("://Recursos/Practica5_sprites.png");
    *ImgMainChar = imagen.copy(x,y,ancho,alto);
    setPos(0,0);
    //setPixmap(ImgMainChar);
}

mainchar::~mainchar()
{
    delete movement_input;
    delete ImgMainChar;
    delete Se_Mueve;
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

