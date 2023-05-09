
#include "character.h"

Character::Character()
{
    Pos_x = new int;
    Pos_y = new int;
    *Pos_x = Start_Point_x;
    *Pos_y = Start_Point_y;
    Movement_Speed = Walk_Velocity;
    Walk_Animation_Speed = Walk_Animation_Velocity;
    Walk_Animation_Frame_Ammount = Ammount_of_Frames_Walk;
}

Character::~Character()
{
    delete Pos_x;
    delete Pos_y;
}

void Character::Movement(char *direction)
{
    if (*direction == 'u'){

    }
    else if (*direction == 'd'){

    }
}

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



