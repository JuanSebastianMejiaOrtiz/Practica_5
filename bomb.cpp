
#include "bomb.h"

bomb::bomb()
{
    //Set Memory for Atributes
    bomb_timer = new QTimer;
    Bomb_Cooldown = new QTimer;
    Already_Exist = new bool;

    //Set Default Values
        //Animation
    Bomb_Animation_Speed = bomb_Animation_Speed; //from global_macros.h
    Bomb_Animation_Actual_Frame = 0;
    Bomb_Animation_Moving_Repeat = 0;
    end_explosion = 0;
        //Other
    *Already_Exist = 0;
    adjust_size_sprite = 0;

    //Set Sprite
    QPixmap imagen;
    int x = (7 * wall_ancho) + (bomb_charge_frame_ammount * bomb_ancho);
    int y = (number_lines_mc * alto_mainchar);
    int WIDTH = (bomb_ancho * bomb_charge_frame_ammount) + (wall_Destruction_Frame_Ammount * wall_ancho);
    int HEIGHT = bomb_alto + (explosion_alto_box);
    imagen.load("://Recursos/Practica5_sprites.png");
    *full = imagen.copy(x, y, WIDTH, HEIGHT);

    //Connect and Start bomb_timer
    connect(Bomb_Cooldown, SIGNAL(timeout()), this, SLOT(Kaboom()));
    connect(bomb_timer, SIGNAL(timeout()), this, SLOT(Bomb_Moving()));
}

bomb::~bomb()
{
    delete bomb_timer;
    delete Already_Exist;
}


//Animation Methods
void bomb::Boom()
{

}

void bomb::Plant_Bomb()
{
    if (Bomb_Animation_Moving_Repeat < bomb_charge_animation_repeat){
        //Animation
        if (Bomb_Animation_Actual_Frame < bomb_charge_frame_ammount){
            Select_sprite(Bomb_Animation_Actual_Frame, 0);
            Scale_sprite(Scale);
            Show_Sprite(1);
            Bomb_Animation_Actual_Frame++;
        }
        else if (Bomb_Animation_Actual_Frame == bomb_charge_frame_ammount){
            Bomb_Animation_Actual_Frame = 0;
            Bomb_Animation_Moving_Repeat++;
        }
    }
    else{
        Set_kaboom(1);
    }
}

void bomb::kaboom1()
{
    if (!adjust_size_sprite){
        adjust_size_sprite = 1;
        *actual = actual->copy(0, bomb_alto, (explosion_ancho_frame_ammount * explosion_ancho_box), (explosion_alto_frame_ammount * explosion_alto_box));
        Set_Width_Sprite(explosion_ancho_box * explosion_ancho_frame_ammount);
        Set_Height_Sprite(explosion_alto_box * explosion_alto_frame_ammount);
        explosion_x = 0;
        explosion_y = 0;
        change_line = 0;
    }
    if (Bomb_Animation_Actual_Frame < explosion_frame_ammount){
        Select_sprite(explosion_x, explosion_y);
        Scale_sprite(Scale);
        Show_Sprite(1);

        if (Bomb_Animation_Actual_Frame+1 == explosion_frame_ammount/2){
            explosion_y = 1;
            explosion_x = 0;
            change_line = 1;
        }

        Bomb_Animation_Actual_Frame++;
        if (!change_line){
            explosion_x++;
            change_line = 0;
        }
    }
    else if (Bomb_Animation_Actual_Frame == explosion_frame_ammount){
        end_explosion = 1;
    }
}

void bomb::kaboom2()
{
    if (Bomb_Animation_Actual_Frame > 0){
        Select_sprite(explosion_x, explosion_y);
        Scale_sprite(Scale);
        Show_Sprite(1);

        if (Bomb_Animation_Actual_Frame-1 == explosion_frame_ammount/2){
            explosion_y = 0;
            explosion_x = 1;
            change_line = 1;
        }

        Bomb_Animation_Actual_Frame--;
        if (!change_line){
            explosion_x = 0;
            change_line = 0;
        }

    }
    else if (Bomb_Animation_Actual_Frame == 0){
        end_explosion = 0;
        Bomb_Cooldown->stop();
        bomb_timer->stop();
    }
}

    //SLOTS
void bomb::Kaboom()
{
    if (!end_explosion){
        kaboom1();
    }
    else{
        kaboom2();
    }

}

void bomb::Bomb_Moving()
{
    if (!Get_kaboom()){
        Plant_Bomb();
    }
    else{
        Kaboom();
    }
}


//Set and Get Methods
    //kaboom
void bomb::Set_kaboom(bool boom)
{
    kaboom = boom;
}

bool bomb::Get_kaboom()
{
    return kaboom;
}
    //Already_Exist
void bomb::Set_Already_Exist(bool exist){
    *Already_Exist = exist;
}

bool bomb::Get_Already_Exist(){
    return *Already_Exist;
}

