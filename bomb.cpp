
#include "bomb.h"

bomb::bomb()
{
    //Assign Memory for Attributes
    bomb_timer = new QTimer;
    Bomb_Detonate = new QTimer;
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
    exploted = false;
        //Animation
            //Bomb
    Bomb_Animation_Speed = bomb_Animation_Speed;
    Bomb_Animation_Actual_Frame = 0;
    contador_bomb = 0;
            //Explosion
    explosion_x = 0;
    explosion_y = 0;
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
    explosion_x++;

    if (explosion_x == explosion_ammount_per_line){
        explosion_x = 0;
        explosion_y++;
    }

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
        Show_Sprite(0);
        exploted = 1;
        emit start_explosion(Bomb_Detonate);
    }
}

void bomb::Bomb_Explosion_Animation(){
    if (explosion_y == explosion_frame_ammount){
        Bomb_Detonate->stop();
        Set_Default_Values();
        emit end_explosion();
    }
    else{
        //Seleccionar explosion
        Explosion_Select_Sprite(explosion_x, explosion_y);
        //Selecciono los sprites individuales
        Scale_sprite(Scale);
        Show_Sprite(1);

        //Cambio de la explosion que se esta eligiendo
        kaboom1();
    }
}


//Set and Get Methods
void bomb::Set_Default_Values(){
    Bomb_Animation_Actual_Frame = 0;
    explosion_x = 0;
    explosion_y = 0;
    contador_bomb = 0;
    activate_bomb(0);
    exploted = 0;
}

bool bomb::is_activated()
{
    return is_active;
}

void bomb::activate_bomb(bool act)
{
    is_active = act;
}

