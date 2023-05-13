
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
    Walk_Animation_Speed = Walk_Animation_Velocity;
    Walk_Animation_Actual_Frame = 0;

    //Inicializar timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Walk_Animation()));
}

Character::~Character()
{
    delete Pos_x;
    delete Pos_y;
    delete direction;
    delete timer;
}

//Movement
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

void Character::Move()
{
    Movement();
    Walk_Animation();
}

//Animations
void Character::Walk_Animation()
{
    if (*direction == 'u'){
        Walk_Up_Animation();
    }
    else if (*direction == 'd'){
        Walk_Down_Animation();
    }
    else if (*direction == 'l'){
        Walk_Left_Animation();
    }
    else if (*direction == 'r'){
        Walk_Right_Animation();
    }
}

void Character::Walk_Up_Animation()
{
    if (Walk_Animation_Actual_Frame < Walk_Animation_Frame_Ammount){
        Select_sprite( (3+Walk_Animation_Actual_Frame), 1);
        Show_Sprite(1);
    }
    else{
        timer->stop();
        Walk_Animation_Actual_Frame = 0;
    }
}

void Character::Walk_Down_Animation()
{
    if (Walk_Animation_Actual_Frame < Walk_Animation_Frame_Ammount){
        Select_sprite( (3+Walk_Animation_Actual_Frame), 0);
        Show_Sprite(1);
    }
    else{
        timer->stop();
        Walk_Animation_Actual_Frame = 0;
    }
}

void Character::Walk_Left_Animation()
{
    if (Walk_Animation_Actual_Frame < Walk_Animation_Frame_Ammount){
        Select_sprite( (Walk_Animation_Actual_Frame), 0);
        Show_Sprite(1);
    }
    else{
        timer->stop();
        Walk_Animation_Actual_Frame = 0;
    }
}

void Character::Walk_Right_Animation()
{
    if (Walk_Animation_Actual_Frame < Walk_Animation_Frame_Ammount){
        Select_sprite( (Walk_Animation_Actual_Frame), 1);
        Show_Sprite(1);
    }
    else{
        timer->stop();
        Walk_Animation_Actual_Frame = 0;
    }
}

