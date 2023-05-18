
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
        //Other
    *Already_Exist = 0;

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
void bomb::Bomb_Moving()
{
    if (Get_kaboom()){
        if (Bomb_Animation_Moving_Repeat < bomb_charge_animation_repeat){
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
            bomb_timer->stop();
            Set_kaboom(1);
        }
    }
}

void bomb::Boom()
{

}

void bomb::Plant_Bomb()
{
    if (!Get_Already_Exist()) {
        if (!Bomb_Cooldown->isActive()) {
            // Coloca la bomba y establece Already_Exist en verdadero
            Set_Already_Exist(true);
            // Inicia el temporizador de animación de la bomba
            bomb_timer->start(Bomb_Animation_Speed);
            // Inicia el temporizador de enfriamiento (cooldown)
            Bomb_Cooldown->start(bomb_Cooldown);
        }
    }
}

void bomb::Kaboom()
{

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

