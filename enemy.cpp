
#include "enemy.h"

enemy::enemy() : Character((enemy_pos_x_initial * enemy_posx_block_initial), (enemy_posy_block_initial * enemy_pos_y_initial))
{
    //Assign Memory for Attributes

    //Set Default Values
    Enemy_Dead_Actual_Frame = 0;

    //Obtain QPixmap full
    QPixmap imagen;
    int x = 0;
    int y = (number_lines_mc * alto_mainchar) + bomb_alto + (explosion_alto_box * explosion_alto_frame_ammount) + PowerUp_alto;
    int WIDTH = ((enemy_Walk_Animation_Frame_Ammount * 2) + enemy_Dead_Animation_Frame_Ammount) * enemy_ancho;
    int HEIGHT = (enemy_Quantity * enemy_alto);
    imagen.load("://Recursos/Practica5_sprites.png");
    *full = imagen.copy(x, y, WIDTH, HEIGHT);

    //Connect and Start Timer
    connect(&Dead_Timer, SIGNAL(timeout()), this, SLOT(Dead_Animation()));
    Dead_Timer.start();
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
            Dead_Timer.stop();
            Enemy_Dead_Actual_Frame = 0;
            Show_Sprite(0);
        }
    }
}

