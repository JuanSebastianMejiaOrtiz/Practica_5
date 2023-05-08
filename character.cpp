
#include "character.h"

Character::Character()
{
    Pos_x = new int;
    Pos_y = new int;
    *Pos_x = Start_Point_x;
    *Pos_y = Start_Point_y;
    Movement_Speed = Walk_Velocity;
    Walk_Animation_Speed = Walk_Animation_Velocity;
}

void Character::Walk_Up_Animation()
{
    delete Pos_x;
    delete Pos_y;
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

void Character::Movement(char *direction)
{
    if (*direction == 'u'){
        *Pos_y += Movement_Speed;

    }
    else if (*direction == 'd'){
        *Pos_y -= Movement_Speed;

    }
}



