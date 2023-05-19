
#include "wall.h"


Wall::Wall(int xPos, int yPos, bool Destructible)
{
    //Assign Memory for Attributes
    Wall_Destructible = new bool;
    Wall_Exist = new bool;
    Wall_Time = new QTimer;

    //Set Default Values
    Set_Wall_Pos_x(xPos*wall_ancho*2);
    Set_Wall_Pos_y(yPos*wall_alto*2);
    Set_Wall_Destructible(Destructible);
    Set_Wall_Exist(1);
    Wall_Destruction_Speed = wall_Destruction_Speed;

    //Load Imagen Wall
    QPixmap img;
    img.load("://Recursos/Practica5_sprites.png");
    *full = img.copy(bomb_ancho*bomb_charge_frame_ammount, alto_mainchar*number_lines_mc, wall_ancho*(wall_Destruction_Frame_Ammount+2), wall_alto);

    //Connect and Start Timer
    connect(Wall_Time, SIGNAL(timeout()), this, SLOT(Wall_Destruction_Animation()));
    //Wall_Time->start(Wall_Destruction_Speed);
}

Wall::~Wall()
{
    if (Get_Wall_Destructible()){
        delete Wall_Time;
    }
    delete Wall_Destructible;
}

void Wall::Set_Wall_Pos_x(int pos)
{
    Wall_Pos_x = pos;
}

int Wall::Get_Wall_Pos_x()
{
    return Wall_Pos_x;
}

void Wall::Set_Wall_Pos_y(int pos)
{
    Wall_Pos_y = pos;
}

int Wall::Get_Wall_Pos_y()
{
    return Wall_Pos_y;
}

void Wall::Set_Wall_Destructible(bool DoNd)
{
    *Wall_Destructible = DoNd;
}

bool Wall::Get_Wall_Destructible()
{
    return *Wall_Destructible;
}

void Wall::Set_Wall_Exist(bool exist)
{
    *Wall_Exist = exist;
}

bool Wall::Get_Wall_Exist()
{
    return *Wall_Exist;
}

void Wall::Wall_Destruction_Animation()
{
    if (Get_Wall_Destructible()){
        if (Wall_Destruction_Actual_Frame < wall_Destruction_Frame_Ammount){
            Select_sprite(Wall_Destruction_Actual_Frame + 1, 0);
            Scale_sprite(Scale);
            Show_Sprite(1);
            Wall_Destruction_Actual_Frame++;
        }
        else if (Wall_Destruction_Actual_Frame == wall_Destruction_Frame_Ammount){
            Wall_Time->stop();
            Show_Sprite(0);
            Set_Wall_Exist(0);
        }
    }
}
