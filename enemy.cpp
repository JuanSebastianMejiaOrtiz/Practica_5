
#include "enemy.h"

enemy::enemy() : Character(enemy_pos_x_initial, (enemy_posy_block_initial * enemy_pos_y_initial), 0)
{
    //Assign Memory for Attributes
    Dead_Timer = new QTimer;
    Change_Move_Timer = new QTimer;
    Enemy_Move_Timer = new QTimer;

    //Set Default Values
    Enemy_Dead_Actual_Frame = 0;
    Set_Direction('l');

    //Obtain QPixmap full
    QPixmap imagen;
    int x = 0;
    int y = (number_lines_mc * alto_mainchar) + bomb_alto + (explosion_alto_box * explosion_alto_frame_ammount * 2) + PowerUp_alto;
    int WIDTH = ((enemy_Walk_Animation_Frame_Ammount * 2) + enemy_Dead_Animation_Frame_Ammount) * enemy_ancho;
    int HEIGHT = (enemy_Quantity * enemy_alto);
    imagen.load("://Recursos/Practica5_sprites.png");
    *full = imagen.copy(x, y, WIDTH, HEIGHT);

    //Connect and Start Timer
    connect(Dead_Timer, SIGNAL(timeout()), this, SLOT(Dead_Animation()));
    connect(Change_Move_Timer, SIGNAL(timeout()), this, SLOT(Enemy_Set_Direction()));
    connect(Enemy_Move_Timer, SIGNAL(timeout()), SLOT(Enemy_Move()));
    Dead_Timer->start(enemy_Dead_Animation_Speed);
    Change_Move_Timer->start(enemy_change_direction);
    Enemy_Move_Timer->start(Check);
}

enemy::~enemy()
{
    delete Dead_Timer;
    delete Change_Move_Timer;
}

void enemy::Enemy_Set_Direction()
{
    if (Get_Direction() == 'l'){
        Set_Direction('r');
    }
    else if (Get_Direction() == 'r'){
        Set_Direction('l');
    }
    Move();
}

void enemy::Dead_Animation()
{
    if (!Get_isAlive()){
        if (Enemy_Dead_Actual_Frame < enemy_Dead_Animation_Frame_Ammount){
            Select_sprite((enemy_Walk_Animation_Frame_Ammount + Enemy_Dead_Actual_Frame), 0);
            Scale_sprite(Scale);
            Show_Sprite(1);
            Enemy_Dead_Actual_Frame++;
        }
        else if (Enemy_Dead_Actual_Frame == enemy_Dead_Animation_Frame_Ammount){
            Dead_Timer->stop();
            Enemy_Dead_Actual_Frame = 0;
            Show_Sprite(0);
        }
    }
}


//Movement
void enemy::Enemy_Move(){
    if (Get_isAlive()){
        Enemy_Movement();
        Enemy_Animation();
    }
}

void enemy::Enemy_Movement()
{
    if (Get_Direction() == 'u'){
        *Pos_y -= enemy_Speed;
    }
    else if (Get_Direction() == 'd'){
        *Pos_y += enemy_Speed;
    }
    else if (Get_Direction() == 'l'){
        *Pos_x -= enemy_Speed;
    }
    else if (Get_Direction() == 'r'){
        *Pos_x += enemy_Speed;
    }

    setPos(QPointF(*Pos_x, *Pos_y));
}

void enemy::Enemy_Animation(){
    if(Get_Direction() == 'u' || Get_Direction() == 'r'){
        Enemy_Animation_Right();
    }
    else if (Get_Direction() == 'd' || Get_Direction() == 'l'){
        Enemy_Animation_Left();
    }
}

void enemy::Enemy_Animation_Right(){
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

void enemy::Enemy_Animation_Left(){
    if (Walk_Animation_Actual_Frame < Walk_Animation_Frame_Ammount_mc){
        Select_sprite( (enemy_Walk_Animation_Frame_Ammount + Walk_Animation_Actual_Frame), 0);
        Scale_sprite(Scale);
        Show_Sprite(1);
        Walk_Animation_Actual_Frame++;
    }
    else{
        timer->stop();
        Walk_Animation_Actual_Frame = 0;
    }
}
