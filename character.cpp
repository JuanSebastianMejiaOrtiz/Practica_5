
#include "character.h"

Character::Character(int Start_Point_x, int Start_Point_y)
{
    //Asignar memoria
    Pos_x = new int;
    Pos_y = new int;
    direction = new char;
    timer = new QTimer(this);
    isAlive = new bool;

    //Ponerles valor default
    *Pos_x = Start_Point_x;
    *Pos_y = Start_Point_y;
    Movement_Speed = Walk_Speed_mc;
    *isAlive = 1;

    //Animation
    Walk_Animation_Speed = _Walk_Animation_Speed_mc;
    Walk_Animation_Actual_Frame = 0;

    //Connect and Start Timer
    connect(timer, SIGNAL(timeout()), this, SLOT(Walk_Animation()));
    timer->start(Walk_Animation_Speed);
}

Character::~Character()
{
    delete Pos_x;
    delete Pos_y;
    delete direction;
    delete timer;
    delete isAlive;
}

//Movement
void Character::Movement()
{
    if (Get_Direction() == 'u'){
        *Pos_y -= Movement_Speed;
    }
    else if (Get_Direction() == 'd'){
        *Pos_y += Movement_Speed;
    }
    else if (Get_Direction() == 'l'){
        *Pos_x -= Movement_Speed;
    }
    else if (Get_Direction() == 'r'){
        *Pos_x += Movement_Speed;
    }

    setPos(QPointF(*Pos_x, *Pos_y));
}

void Character::Move()
{
    Movement();

    Walk_Animation();
}

void Character::Set_Direction(char car)
{
    *direction = car;
}

char Character::Get_Direction()
{
    return *direction;
}

void Character::Set_Pos_x(int new_pos)
{
    *Pos_x = new_pos;
}

int Character::Get_Pos_x()
{
    return *Pos_x;
}

void Character::Set_Pos_y(int new_pos)
{
    *Pos_y = new_pos;
}

int Character::Get_Pos_y()
{
    return *Pos_y;
}

void Character::Set_isAlive(bool LoD)
{
    *isAlive = LoD;
}

bool Character::Get_isAlive()
{
    return *isAlive;
}

//Animations
void Character::Walk_Animation()
{
    if (Get_Direction() == 'u'){
        Walk_Up_Animation();
    }
    else if (Get_Direction() == 'd'){
        Walk_Down_Animation();
    }
    else if (Get_Direction() == 'l'){
        Walk_Left_Animation();
    }
    else if (Get_Direction() == 'r'){
        Walk_Right_Animation();
    }
}

void Character::Walk_Up_Animation()
{
    if (Walk_Animation_Actual_Frame < Walk_Animation_Frame_Ammount_mc){
        Select_sprite( (Walk_Animation_Frame_Ammount_mc+Walk_Animation_Actual_Frame), 1);
        Scale_sprite(Scale);
        Show_Sprite(1);
        Walk_Animation_Actual_Frame++;
    }
    else{
        timer->stop();
        Walk_Animation_Actual_Frame = 0;
    }
}

void Character::Walk_Down_Animation()
{
    if (Walk_Animation_Actual_Frame < Walk_Animation_Frame_Ammount_mc){
        Select_sprite( (Walk_Animation_Frame_Ammount_mc+Walk_Animation_Actual_Frame), 0);
        Scale_sprite(Scale);
        Show_Sprite(1);
        Walk_Animation_Actual_Frame++;
    }
    else{
        timer->stop();
        Walk_Animation_Actual_Frame = 0;
    }
}

void Character::Walk_Left_Animation()
{
    if (Walk_Animation_Actual_Frame < Walk_Animation_Frame_Ammount_mc){
        Select_sprite( (Walk_Animation_Actual_Frame), 0);
        Scale_sprite(Scale);
        Show_Sprite(1);
        Walk_Animation_Actual_Frame++;
    }
    else{
        timer->stop();
        Walk_Animation_Actual_Frame = 0;
    }
}

void Character::Walk_Right_Animation()
{
    if (Walk_Animation_Actual_Frame < Walk_Animation_Frame_Ammount_mc){
        Select_sprite( (Walk_Animation_Actual_Frame), 1);
        Scale_sprite(Scale);
        Show_Sprite(1);
        Walk_Animation_Actual_Frame++;
    }
    else{
        timer->stop();
        Walk_Animation_Actual_Frame = 0;
    }
}

