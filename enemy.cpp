
#include "enemy.h"

enemy::enemy() : Character(enemy_pos_x_initial, (enemy_posy_block_initial * enemy_pos_y_initial))
{
    //Assign Memory for Attributes
    Dead_Timer = new QTimer;
    Move_Timer = new QTimer;

    //Set Default Values
    Enemy_Dead_Actual_Frame = 0;
    Set_Direction('l');

    //Obtain QPixmap full
    QPixmap imagen;
    int x = 0;
    int y = (number_lines_mc * alto_mainchar) + bomb_alto + (explosion_alto_box * explosion_alto_frame_ammount) + PowerUp_alto;
    int WIDTH = ((enemy_Walk_Animation_Frame_Ammount * 2) + enemy_Dead_Animation_Frame_Ammount) * enemy_ancho;
    int HEIGHT = (enemy_Quantity * enemy_alto);
    imagen.load("://Recursos/Practica5_sprites.png");
    *full = imagen.copy(x, y, WIDTH, HEIGHT);

    //Connect and Start Timer
    connect(Dead_Timer, SIGNAL(timeout()), this, SLOT(Dead_Animation()));
    connect(Move_Timer, SIGNAL(timeout()), this, SLOT(Enemy_Set_Direction()));
    Dead_Timer->start(enemy_Dead_Animation_Speed);
    Move_Timer->start(enemy_change_direction);
}

enemy::~enemy()
{
    delete Dead_Timer;
    delete Move_Timer;
}

void enemy::Enemy_Set_Direction()
{
    if (Get_Direction() == 'l'){
        Set_Direction('r');
    }
    else if (Get_Direction() == 'r'){
        Set_Direction('l');
    }
}

void enemy::Dead_Animation()
{
    if (!Get_isAlive()){
        if (Enemy_Dead_Actual_Frame < enemy_Dead_Animation_Frame_Ammount){
            Select_sprite((enemy_Walk_Animation_Frame_Ammount + Enemy_Dead_Actual_Frame), 0);
            Scale_sprite(Scale);
            Show_Sprite(1);
            Enemy_Dead_Actual_Frame++;
        }
        else if (Enemy_Dead_Actual_Frame == enemy_Dead_Animation_Frame_Ammount){
            Dead_Timer->stop();
            Enemy_Dead_Actual_Frame = 0;
            Show_Sprite(0);
        }
    }
}

