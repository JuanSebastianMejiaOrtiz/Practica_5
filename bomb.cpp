
#include "bomb.h"

bomb::bomb()
{
    //Assign Memory for Attributes
    bomb_timer = new QTimer;
    Bomb_Detonate = new QTimer;
    Bomb_pos_x = new int;
    Bomb_pos_y = new int;
    Full_Explosions = new QPixmap;

    //Set Sprite
    QPixmap imagen;
    int x = 0;
    int y = (number_lines_mc * alto_mainchar);
    int WIDTH = (bomb_ancho * bomb_charge_frame_ammount) + (wall_Destruction_Frame_Ammount * wall_ancho) + wall_ancho;
    int HEIGHT = bomb_alto + (explosion_alto_box * explosion_alto_frame_ammount * 2);
    imagen.load(":/Recursos/Practica5_sprites.png");
    *full = imagen.copy(x, y, WIDTH, HEIGHT);

    //Set Default Values
    is_active = false;
        //Animation
            //Bomb
    Bomb_Animation_Speed = bomb_Animation_Speed;
    Bomb_Animation_Actual_Frame = 0;
            //Explosion
    *Full_Explosions = full->copy(0, bomb_alto, (explosion_ancho_frame_ammount * explosion_ancho_box), (explosion_alto_frame_ammount * explosion_alto_box));

    //Connect and Start bomb_timer
    connect(bomb_timer, SIGNAL(timeout()), this, SLOT(Bomb_Plant_Animation()));
    connect(Bomb_Detonate, SIGNAL(timeout()), this, SLOT(Bomb_Explosion_Animation()));
}

bomb::~bomb()
{
    delete bomb_timer;
    delete Bomb_Detonate;
    delete Full_Explosions;
}


//Animation Methods
void bomb::Plant_Bomb()
{
    //Animation planted bomb
    if (Bomb_Animation_Actual_Frame < bomb_charge_frame_ammount){
        Select_sprite(Bomb_Animation_Actual_Frame, 0);
        Scale_sprite(Scale);
        Show_Sprite(1);

        Bomb_Animation_Actual_Frame++;
        contador_bomb++;
    }
    else if (Bomb_Animation_Actual_Frame == bomb_charge_frame_ammount){
        Bomb_Animation_Actual_Frame = 0;
    }
}

void bomb::kaboom1()
{
    //Animation explosion
}

void bomb::Explosion_Select_Sprite(int _x, int _y)
{
    int x = (_x * explosion_ancho_box) * explosion_ancho_frame_ammount;
    int y = (_y * explosion_alto_box) * explosion_alto_frame_ammount;
    int WIDTH = explosion_ancho_frame_ammount * explosion_ancho_box;
    int HEIGHT = explosion_alto_frame_ammount * explosion_alto_box;
    *actual = Full_Explosions->copy(x, y, WIDTH, HEIGHT);
}

    //SLOTS
void bomb::Bomb_Plant_Animation()
{
    if (contador_bomb < bomb_charge_animation_repeat){
        Plant_Bomb();
    }
    else{
        bomb_timer->stop();
        Set_Default_Values();
        Bomb_Detonate->start(explosion_Animation_Speed);
    }
}

void bomb::Bomb_Explosion_Animation(){

}

//Set and Get Methods
void bomb::Set_Default_Values(){
    Bomb_Animation_Actual_Frame = 0;
    explosion_x = 0;
    explosion_y = 0;
}

bool bomb::is_activated()
{
    return is_active;
}

void bomb::activate_bomb(bool act)
{
    is_active = act;
}
