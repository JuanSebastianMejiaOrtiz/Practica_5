
#include "character.h"

Character::Character(int Start_Point_x, int Start_Point_y)
{
    //Asignar memoria
    Pos_x = new int;
    Pos_y = new int;
    direction = new char;

    //Ponerles valor default
    *Pos_x = Start_Point_x;
    *Pos_y = Start_Point_y;
    Movement_Speed = Walk_Velocity;

    //Animation
    //Walk_Animation_Speed = Walk_Animation_Velocity;
    //Walk_Animation_Frame_Ammount = Ammount_of_Frames_Walk;

    //Inicializar timer
    timer = new QTimer(this);
}

Character::~Character()
{
    delete Pos_x;
    delete Pos_y;
    delete direction;
    delete timer;
}

void Character::Movement()
{
    if (*direction == 'u'){
        *Pos_y -= Movement_Speed;
    }
    else if (*direction == 'd'){
        *Pos_y += Movement_Speed;
    }
    else if (*direction == 'l'){
        *Pos_y -= Movement_Speed;
    }
    else if (*direction == 'r'){
        *Pos_y += Movement_Speed;
    }

    setPos(QPointF(*Pos_x, *Pos_y));
}

/*
void Character::Walk_Up_Animation()
{
    //if ()
}

void Character::Walk_Down_Animation()
{

}

void Character::Walk_Left_Animation()
{

}

void Character::Walk_Right_Animation()
{

}
*/
