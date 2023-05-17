
#include "mainchar.h"

mainchar::mainchar() : Character(0, 0)
{
    //Reservar memoria variables
    Dead_Timer = new QTimer;
    Dead_Actual_Frame = new int;

    //Poner valores por defecto
    *Dead_Actual_Frame = 0;

    //Obtain QPixmap full
    QPixmap imagen;
    imagen.load("://Recursos/Practica5_sprites.png");
    *full = imagen.copy(0, 0, ancho_mainchar*number_cols_mc, alto_mainchar*number_lines_mc);

    //Connect and Start Dead_Timer
    connect(Dead_Timer, SIGNAL(timeout()), this, SLOT(Dead_Animation()));
    Dead_Timer->start(Dead_Animation_Speed_mc);
}

mainchar::~mainchar()
{
    delete Dead_Timer;
}

void mainchar::keyPressEvent(QKeyEvent *event)
{
    if (Get_isAlive()){
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
}

void mainchar::Dead_Animation()
{
    if (!Get_isAlive()){
        if (*Dead_Actual_Frame < Dead_Animation_Frame_Ammount_mc){
            Select_sprite(*Dead_Actual_Frame, 2);
            Scale_sprite(Scale);
            Show_Sprite(1);
            (*Dead_Actual_Frame)++;
        }
        else if (*Dead_Actual_Frame == Dead_Animation_Frame_Ammount_mc){
            Dead_Timer->stop();
            *Dead_Actual_Frame = 0;
            Show_Sprite(0);
        }
    }
}

