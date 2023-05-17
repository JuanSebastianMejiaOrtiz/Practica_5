
#include "wall.h"


Wall::Wall(int xPos, int yPos, bool Destructible)
{
    //Inicializar variables
    Wall_Pos_x = new int;
    Wall_Pos_y = new int;
    Wall_Destructible = new bool;
    if (Destructible){
        Wall_Time = new QTimer;
    }

    //Ponerles valores default
    Set_Wall_Pos_x(xPos*wall_ancho*2);
    Set_Wall_Pos_y(yPos*wall_alto*2);
    Set_Wall_Destructible(Destructible);

    //Cargar Imagen Wall
    QPixmap img;
    img.load("://Recursos/Practica5_sprites.png");
    *full = img.copy(bomb_ancho*bomb_charge_frame_ammount, alto_mainchar*number_lines_mc, wall_ancho*(wall_Destruction_Frame_Ammount+2), wall_alto);
}

Wall::~Wall()
{
    delete Wall_Pos_x;
    delete Wall_Pos_y;
    if (Get_Wall_Destructible()){
        delete Wall_Time;
    }
    delete Wall_Destructible;
}

void Wall::Set_Wall_Pos_x(int pos)
{
    *Wall_Pos_x = pos;
}

int Wall::Get_Wall_Pos_x()
{
    return *Wall_Pos_x;
}

void Wall::Set_Wall_Pos_y(int pos)
{
    *Wall_Pos_y = pos;
}

int Wall::Get_Wall_Pos_y()
{
    return *Wall_Pos_y;
}

void Wall::Set_Wall_Destructible(bool DoNd)
{
    *Wall_Destructible = DoNd;
}

bool Wall::Get_Wall_Destructible()
{
    return *Wall_Destructible;
}
