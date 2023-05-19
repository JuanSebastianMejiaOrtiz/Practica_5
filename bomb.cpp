
#include "bomb.h"

bomb::bomb()
{
    //Assign Memory for Attributes
    bomb_timer = new QTimer;
    Bomb_Cooldown = new QTimer;
    Already_Exist = new bool;
    Explosions = new QPixmap;
    Bomb_pos_x = new int;
    Bomb_pos_y = new int;

    //Set Sprite
    QPixmap imagen;
    int x = 0;
    int y = (number_lines_mc * alto_mainchar);
    int WIDTH = (bomb_ancho * bomb_charge_frame_ammount) + (wall_Destruction_Frame_Ammount * wall_ancho);
    int HEIGHT = bomb_alto + (explosion_alto_box);
    imagen.load("://Recursos/Practica5_sprites.png");
    *full = imagen.copy(x, y, WIDTH, HEIGHT);

    //Set Default Values
    //Animation
    Bomb_Animation_Speed = bomb_Animation_Speed; //from global_macros.h
    Bomb_Animation_Actual_Frame = 0;
    explosion_x = 0;
    explosion_y = 0;
        //Other
    *Already_Exist = 0;
    *Explosions = full->copy(0, bomb_alto, (explosion_ancho_frame_ammount * explosion_ancho_box), (explosion_alto_frame_ammount * explosion_alto_box));

    //Connect and Start bomb_timer
    connect(bomb_timer, SIGNAL(timeout()), this, SLOT(Bomb_Animations()));
    connect(Bomb_Cooldown, SIGNAL(timeout()), this, SLOT(Bomb_Check_If_Can_Use()));
}

bomb::~bomb()
{
    delete bomb_timer;
    delete Already_Exist;
    delete Bomb_Cooldown;
    delete Explosions;
}


//Animation Methods
void bomb::Plant_Bomb()
{
    //Animation
    if (Bomb_Animation_Actual_Frame < bomb_charge_frame_ammount){
            Select_sprite(Bomb_Animation_Actual_Frame, 0);
            Scale_sprite(Scale);
            Show_Sprite(1);
            Bomb_Animation_Actual_Frame++;
    }
    else if (Bomb_Animation_Actual_Frame == bomb_charge_frame_ammount){
        Bomb_Animation_Actual_Frame = 0;
        Set_kaboom(1);
    }
}

void bomb::kaboom1()
{
    if (Bomb_Animation_Actual_Frame < explosion_frame_ammount){
        Explosion_Select_Sprite(explosion_x, explosion_y);
        Scale_sprite(Scale);
        Show_Sprite(1);

        Bomb_Animation_Actual_Frame++;
        explosion_x++;
        if (explosion_x == explosion_frame_ammount && explosion_y < 1){
            explosion_x = 0;
            explosion_y++;
        }
    }
    else if (Bomb_Animation_Actual_Frame == explosion_frame_ammount){
        bomb_timer->stop();
    }
}

void bomb::Explosion_Select_Sprite(int _x, int _y)
{
    int x = (_x * explosion_ancho_box) * explosion_ancho_frame_ammount;
    int y = (_y * explosion_alto_box) * explosion_alto_frame_ammount;
    int WIDTH = explosion_ancho_frame_ammount * explosion_ancho_box;
    int HEIGHT = explosion_alto_frame_ammount * explosion_alto_box;
    *actual = Explosions->copy(x, y, WIDTH, HEIGHT);
}

    //SLOTS
void bomb::Bomb_Animations()
{
    if (!Get_kaboom()){
        Plant_Bomb();
    }
    else{
        kaboom1();
    }
}

void bomb::Bomb_Check_If_Can_Use(){
    if (!Get_Already_Exist()){
        bomb_timer->start();
        Set_Already_Exist(1);
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

void bomb::Set_Bomb_pos_x(int x){
    *Bomb_pos_x = x;
}

int bomb::Get_Bomb_pos_x(){
    return *Bomb_pos_x;
}

void bomb::Set_Bomb_pos_y(int y){
    *Bomb_pos_y = y;
}

int bomb::Get_Bomb_pos_y(){
    return *Bomb_pos_y;
}

void bomb::Set_Default_Values(){
    kaboom = 0;
    Bomb_Animation_Actual_Frame = 0;
    explosion_x = 0;
    explosion_y = 0;
    Already_Exist = 0;
}
