
#include "game.h"

game::game()
{
    //Assign Memory for Attributes
        //Characters
            //Main Character
    bomberman = new mainchar();
            //Enemy
    Enemy = new enemy();
        //Walls
    Create_Memory_Limits();
    Create_Memory_Walls();
        //Collisions
    Checking = new QTimer;


    //Set and Add Items
    SetMC();
    SetEnemy();
    SetWalls();

    //Connect and Start Timer
    connect(Checking, SIGNAL(timeout()), this, SLOT(Check_Collisions()));
    Checking->start(Check);
}

game::~game()
{
    delete Checking;
    delete bomberman;
    delete Enemy;
    //Walls
        //Limits
    Delete_Memory_Limits();
        //Inside Walls
    Delete_Memory_Walls();

}

void game::keyPressEvent(QKeyEvent *event)
{
    bomberman->keyPressEvent(event);

    if (!(bomberman->bomba->Get_Already_Exist()) && (bomberman->bomba->Bomb_Cooldown->isActive())){
        addItem(bomberman->bomba);
    }
    else if ((bomberman->bomba->Get_Already_Exist()) && (bomberman->bomba->Bomb_Cooldown->isActive())){
        removeItem(bomberman->bomba);
    }
}

void game::Check_Collisions()
{
    Check_with_mc();
    Check_with_enemy();
}

void game::Check_with_mc(){
    //With Walls
        //Limits
    Walls_with_character(bomberman, Limit_1);
    Walls_with_character(bomberman, Limit_2);
    Walls_with_character(bomberman, Limit_3);
    Walls_with_character(bomberman, Limit_4);
    Walls_with_character(bomberman, Limit_5);
    Walls_with_character(bomberman, Limit_6);
    Walls_with_character(bomberman, Limit_7);
    Walls_with_character(bomberman, Limit_8);
    Walls_with_character(bomberman, Limit_9);
    Walls_with_character(bomberman, Limit_10);
    Walls_with_character(bomberman, Limit_11);
    Walls_with_character(bomberman, Limit_12);
    Walls_with_character(bomberman, Limit_13);
    Walls_with_character(bomberman, Limit_14);
    Walls_with_character(bomberman, Limit_15);
    Walls_with_character(bomberman, Limit_16);
    Walls_with_character(bomberman, Limit_17);
    Walls_with_character(bomberman, Limit_18);
    Walls_with_character(bomberman, Limit_19);
    Walls_with_character(bomberman, Limit_20);
    Walls_with_character(bomberman, Limit_21);
    Walls_with_character(bomberman, Limit_22);
    Walls_with_character(bomberman, Limit_23);
    Walls_with_character(bomberman, Limit_24);
    Walls_with_character(bomberman, Limit_25);
    Walls_with_character(bomberman, Limit_26);
    Walls_with_character(bomberman, Limit_27);
    Walls_with_character(bomberman, Limit_28);
    Walls_with_character(bomberman, Limit_29);
    Walls_with_character(bomberman, Limit_30);
    Walls_with_character(bomberman, Limit_31);
    Walls_with_character(bomberman, Limit_32);
    Walls_with_character(bomberman, Limit_33);
    Walls_with_character(bomberman, Limit_34);
    Walls_with_character(bomberman, Limit_35);
    Walls_with_character(bomberman, Limit_36);
    Walls_with_character(bomberman, Limit_37);
    Walls_with_character(bomberman, Limit_38);
    Walls_with_character(bomberman, Limit_39);
    Walls_with_character(bomberman, Limit_40);
    Walls_with_character(bomberman, Limit_41);
    Walls_with_character(bomberman, Limit_42);
    Walls_with_character(bomberman, Limit_43);
    Walls_with_character(bomberman, Limit_44);
    Walls_with_character(bomberman, Limit_45);
    Walls_with_character(bomberman, Limit_46);
    Walls_with_character(bomberman, Limit_47);
    Walls_with_character(bomberman, Limit_48);
    Walls_with_character(bomberman, Limit_49);
    Walls_with_character(bomberman, Limit_50);
    Walls_with_character(bomberman, Limit_51);
    Walls_with_character(bomberman, Limit_52);
        //Inside Walls
    Walls_with_character(bomberman, wall_1);
    Walls_with_character(bomberman, wall_2);
    Walls_with_character(bomberman, wall_3);
    Walls_with_character(bomberman, wall_4);
    Walls_with_character(bomberman, wall_5);
    Walls_with_character(bomberman, wall_6);
    Walls_with_character(bomberman, wall_7);
    Walls_with_character(bomberman, wall_8);
    Walls_with_character(bomberman, wall_9);
    Walls_with_character(bomberman, wall_10);
    Walls_with_character(bomberman, wall_11);
    Walls_with_character(bomberman, wall_12);
    Walls_with_character(bomberman, wall_13);
    Walls_with_character(bomberman, wall_14);
    Walls_with_character(bomberman, wall_15);
    Walls_with_character(bomberman, wall_16);
    Walls_with_character(bomberman, wall_17);
    Walls_with_character(bomberman, wall_18);
    Walls_with_character(bomberman, wall_19);
    Walls_with_character(bomberman, wall_20);
    Walls_with_character(bomberman, wall_21);
    Walls_with_character(bomberman, wall_22);
    Walls_with_character(bomberman, wall_23);
    Walls_with_character(bomberman, wall_24);
    Walls_with_character(bomberman, wall_25);
    Walls_with_character(bomberman, wall_26);
    Walls_with_character(bomberman, wall_27);
    Walls_with_character(bomberman, wall_28);
    Walls_with_character(bomberman, wall_29);
    Walls_with_character(bomberman, wall_30);
    Walls_with_character(bomberman, wall_31);
    Walls_with_character(bomberman, wall_32);
    Walls_with_character(bomberman, wall_33);
    Walls_with_character(bomberman, wall_34);
    Walls_with_character(bomberman, wall_35);
    Walls_with_character(bomberman, wall_36);
    Walls_with_character(bomberman, wall_37);
    Walls_with_character(bomberman, wall_38);
    Walls_with_character(bomberman, wall_39);
    Walls_with_character(bomberman, wall_40);

    //Collides with enemies
    Enemy_and_Main_Character(bomberman, Enemy);
}

void game::Check_with_enemy(){
    //With Walls
    //Limits
    Walls_with_character(Enemy, Limit_1);
    Walls_with_character(Enemy, Limit_2);
    Walls_with_character(Enemy, Limit_3);
    Walls_with_character(Enemy, Limit_4);
    Walls_with_character(Enemy, Limit_5);
    Walls_with_character(Enemy, Limit_6);
    Walls_with_character(Enemy, Limit_7);
    Walls_with_character(Enemy, Limit_8);
    Walls_with_character(Enemy, Limit_9);
    Walls_with_character(Enemy, Limit_10);
    Walls_with_character(Enemy, Limit_11);
    Walls_with_character(Enemy, Limit_12);
    Walls_with_character(Enemy, Limit_13);
    Walls_with_character(Enemy, Limit_14);
    Walls_with_character(Enemy, Limit_15);
    Walls_with_character(Enemy, Limit_16);
    Walls_with_character(Enemy, Limit_17);
    Walls_with_character(Enemy, Limit_18);
    Walls_with_character(Enemy, Limit_19);
    Walls_with_character(Enemy, Limit_20);
    Walls_with_character(Enemy, Limit_21);
    Walls_with_character(Enemy, Limit_22);
    Walls_with_character(Enemy, Limit_23);
    Walls_with_character(Enemy, Limit_24);
    Walls_with_character(Enemy, Limit_25);
    Walls_with_character(Enemy, Limit_26);
    Walls_with_character(Enemy, Limit_27);
    Walls_with_character(Enemy, Limit_28);
    Walls_with_character(Enemy, Limit_29);
    Walls_with_character(Enemy, Limit_30);
    Walls_with_character(Enemy, Limit_31);
    Walls_with_character(Enemy, Limit_32);
    Walls_with_character(Enemy, Limit_33);
    Walls_with_character(Enemy, Limit_34);
    Walls_with_character(Enemy, Limit_35);
    Walls_with_character(Enemy, Limit_36);
    Walls_with_character(Enemy, Limit_37);
    Walls_with_character(Enemy, Limit_38);
    Walls_with_character(Enemy, Limit_39);
    Walls_with_character(Enemy, Limit_40);
    Walls_with_character(Enemy, Limit_41);
    Walls_with_character(Enemy, Limit_42);
    Walls_with_character(Enemy, Limit_43);
    Walls_with_character(Enemy, Limit_44);
    Walls_with_character(Enemy, Limit_45);
    Walls_with_character(Enemy, Limit_46);
    Walls_with_character(Enemy, Limit_47);
    Walls_with_character(Enemy, Limit_48);
    Walls_with_character(Enemy, Limit_49);
    Walls_with_character(Enemy, Limit_50);
    Walls_with_character(Enemy, Limit_51);
    Walls_with_character(Enemy, Limit_52);
        //Inside Walls
    Walls_with_character(Enemy, wall_1);
    Walls_with_character(Enemy, wall_2);
    Walls_with_character(Enemy, wall_3);
    Walls_with_character(Enemy, wall_4);
    Walls_with_character(Enemy, wall_5);
    Walls_with_character(Enemy, wall_6);
    Walls_with_character(Enemy, wall_7);
    Walls_with_character(Enemy, wall_8);
    Walls_with_character(Enemy, wall_9);
    Walls_with_character(Enemy, wall_10);
    Walls_with_character(Enemy, wall_11);
    Walls_with_character(Enemy, wall_12);
    Walls_with_character(Enemy, wall_13);
    Walls_with_character(Enemy, wall_14);
    Walls_with_character(Enemy, wall_15);
    Walls_with_character(Enemy, wall_16);
    Walls_with_character(Enemy, wall_17);
    Walls_with_character(Enemy, wall_18);
    Walls_with_character(Enemy, wall_19);
    Walls_with_character(Enemy, wall_20);
    Walls_with_character(Enemy, wall_21);
    Walls_with_character(Enemy, wall_22);
    Walls_with_character(Enemy, wall_23);
    Walls_with_character(Enemy, wall_24);
    Walls_with_character(Enemy, wall_25);
    Walls_with_character(Enemy, wall_26);
    Walls_with_character(Enemy, wall_27);
    Walls_with_character(Enemy, wall_28);
    Walls_with_character(Enemy, wall_29);
    Walls_with_character(Enemy, wall_30);
    Walls_with_character(Enemy, wall_31);
    Walls_with_character(Enemy, wall_32);
    Walls_with_character(Enemy, wall_33);
    Walls_with_character(Enemy, wall_34);
    Walls_with_character(Enemy, wall_35);
    Walls_with_character(Enemy, wall_36);
    Walls_with_character(Enemy, wall_37);
    Walls_with_character(Enemy, wall_38);
    Walls_with_character(Enemy, wall_39);
    Walls_with_character(Enemy, wall_40);
}

void game::Walls_with_character(Character *chara, Wall *muro){
    if (chara->collidesWithItem(muro)){
        if (chara->Get_Direction() == 'u'){
            chara->Set_Direction('d');
            chara->Move();
        }
        else if (chara->Get_Direction() == 'd'){
            chara->Set_Direction('u');
            chara->Move();
        }
        else if (chara->Get_Direction() == 'l'){
            chara->Set_Direction('r');
            chara->Move();
        }
        else if (chara->Get_Direction() == 'r'){
            chara->Set_Direction('l');
            chara->Move();
        }
    }
}

void game::Enemy_and_Main_Character(Character *chara, enemy *villian)
{
    if (chara->Get_isAlive()){
        if (chara->collidesWithItem(villian)){
            chara->Set_isAlive(0);
        }
    }
}

//Private
void game::SetMC()
{
    //Set Bomberman
    bomberman->Select_sprite(4, 0);
    bomberman->Scale_sprite(Scale);
    bomberman->Show_Sprite(1);
    addItem(bomberman);
}

void game::SetEnemy(){
    Enemy->Select_sprite(0, 0);
    Enemy->Scale_sprite(Scale);
    Enemy->Show_Sprite(1);
    addItem(Enemy);
}

void game::SetWalls()
{
    Create_Limits();
    Create_Inside_Walls();
}


//Walls
void game::Put_Walls_Sprite(Wall *Wall, int sprite_x, int sprite_y)
{
    Wall->Select_sprite(sprite_x, sprite_y);
    Wall->Scale_sprite(Scale);
    Wall->Show_Sprite(1);
}

void game::Set_Walls_Pos(Wall *Wall, int posx, int posy)
{
    int x = posx * wall_ancho * Scale;
    int y = posy * wall_alto * Scale;

    Wall->Set_Wall_Pos_x(x);
    Wall->Set_Wall_Pos_y(y);
    Wall->setPos(QPointF(Wall->Get_Wall_Pos_x(), Wall->Get_Wall_Pos_y()));
}

void game::Create_Limits()
{
    //Put Limits
    Put_Walls_Sprite(Limit_1, 0, 0);
    Put_Walls_Sprite(Limit_2, 0, 0);
    Put_Walls_Sprite(Limit_3, 0, 0);
    Put_Walls_Sprite(Limit_4, 0, 0);
    Put_Walls_Sprite(Limit_5, 0, 0);
    Put_Walls_Sprite(Limit_6, 0, 0);
    Put_Walls_Sprite(Limit_7, 0, 0);
    Put_Walls_Sprite(Limit_8, 0, 0);
    Put_Walls_Sprite(Limit_9, 0, 0);
    Put_Walls_Sprite(Limit_10, 0, 0);
    Put_Walls_Sprite(Limit_11, 0, 0);
    Put_Walls_Sprite(Limit_12, 0, 0);
    Put_Walls_Sprite(Limit_13, 0, 0);
    Put_Walls_Sprite(Limit_14, 0, 0);
    Put_Walls_Sprite(Limit_15, 0, 0);
    Put_Walls_Sprite(Limit_16, 0, 0);
    Put_Walls_Sprite(Limit_17, 0, 0);
    Put_Walls_Sprite(Limit_18, 0, 0);
    Put_Walls_Sprite(Limit_19, 0, 0);
    Put_Walls_Sprite(Limit_20, 0, 0);
    Put_Walls_Sprite(Limit_21, 0, 0);
    Put_Walls_Sprite(Limit_22, 0, 0);
    Put_Walls_Sprite(Limit_23, 0, 0);
    Put_Walls_Sprite(Limit_24, 0, 0);
    Put_Walls_Sprite(Limit_25, 0, 0);
    Put_Walls_Sprite(Limit_26, 0, 0);
    Put_Walls_Sprite(Limit_27, 0, 0);
    Put_Walls_Sprite(Limit_28, 0, 0);
    Put_Walls_Sprite(Limit_29, 0, 0);
    Put_Walls_Sprite(Limit_30, 0, 0);
    Put_Walls_Sprite(Limit_31, 0, 0);
    Put_Walls_Sprite(Limit_32, 0, 0);
    Put_Walls_Sprite(Limit_33, 0, 0);
    Put_Walls_Sprite(Limit_34, 0, 0);
    Put_Walls_Sprite(Limit_35, 0, 0);
    Put_Walls_Sprite(Limit_36, 0, 0);
    Put_Walls_Sprite(Limit_37, 0, 0);
    Put_Walls_Sprite(Limit_38, 0, 0);
    Put_Walls_Sprite(Limit_39, 0, 0);
    Put_Walls_Sprite(Limit_40, 0, 0);
    Put_Walls_Sprite(Limit_41, 0, 0);
    Put_Walls_Sprite(Limit_42, 0, 0);
    Put_Walls_Sprite(Limit_43, 0, 0);
    Put_Walls_Sprite(Limit_44, 0, 0);
    Put_Walls_Sprite(Limit_45, 0, 0);
    Put_Walls_Sprite(Limit_46, 0, 0);
    Put_Walls_Sprite(Limit_47, 0, 0);
    Put_Walls_Sprite(Limit_48, 0, 0);
    Put_Walls_Sprite(Limit_49, 0, 0);
    Put_Walls_Sprite(Limit_50, 0, 0);
    Put_Walls_Sprite(Limit_51, 0, 0);
    Put_Walls_Sprite(Limit_52, 0, 0);

    //Add Limits to Scene
    Add_Limits_to_Scene();

    //Set Limits
    Set_Walls_Pos(Limit_1, 0, 0);
    Set_Walls_Pos(Limit_2, 1, 0);
    Set_Walls_Pos(Limit_3, 2, 0);
    Set_Walls_Pos(Limit_4, 3, 0);
    Set_Walls_Pos(Limit_5, 4, 0);
    Set_Walls_Pos(Limit_6, 5, 0);
    Set_Walls_Pos(Limit_7, 6, 0);
    Set_Walls_Pos(Limit_8, 7, 0);
    Set_Walls_Pos(Limit_9, 8, 0);
    Set_Walls_Pos(Limit_10, 9, 0);
    Set_Walls_Pos(Limit_11, 10, 0);
    Set_Walls_Pos(Limit_12, 11, 0);
    Set_Walls_Pos(Limit_13, 12, 0);
    Set_Walls_Pos(Limit_14, 13, 0);
    Set_Walls_Pos(Limit_15, 14, 0);
    Set_Walls_Pos(Limit_16, 15, 0);
    Set_Walls_Pos(Limit_17, 0, 11);
    Set_Walls_Pos(Limit_18, 1, 11);
    Set_Walls_Pos(Limit_19, 2, 11);
    Set_Walls_Pos(Limit_20, 3, 11);
    Set_Walls_Pos(Limit_21, 4, 11);
    Set_Walls_Pos(Limit_22, 5, 11);
    Set_Walls_Pos(Limit_23, 6, 11);
    Set_Walls_Pos(Limit_24, 7, 11);
    Set_Walls_Pos(Limit_25, 8, 11);
    Set_Walls_Pos(Limit_26, 9, 11);
    Set_Walls_Pos(Limit_27, 10, 11);
    Set_Walls_Pos(Limit_28, 11, 11);
    Set_Walls_Pos(Limit_29, 12, 11);
    Set_Walls_Pos(Limit_30, 13, 11);
    Set_Walls_Pos(Limit_31, 14, 11);
    Set_Walls_Pos(Limit_32, 15, 11);
    Set_Walls_Pos(Limit_33, 0, 1);
    Set_Walls_Pos(Limit_34, 0, 2);
    Set_Walls_Pos(Limit_35, 0, 3);
    Set_Walls_Pos(Limit_36, 0, 4);
    Set_Walls_Pos(Limit_37, 0, 5);
    Set_Walls_Pos(Limit_38, 0, 6);
    Set_Walls_Pos(Limit_39, 0, 7);
    Set_Walls_Pos(Limit_40, 0, 8);
    Set_Walls_Pos(Limit_41, 0, 9);
    Set_Walls_Pos(Limit_42, 0, 10);
    Set_Walls_Pos(Limit_43, 15, 1);
    Set_Walls_Pos(Limit_44, 15, 2);
    Set_Walls_Pos(Limit_45, 15, 3);
    Set_Walls_Pos(Limit_46, 15, 4);
    Set_Walls_Pos(Limit_47, 15, 5);
    Set_Walls_Pos(Limit_48, 15, 6);
    Set_Walls_Pos(Limit_49, 15, 7);
    Set_Walls_Pos(Limit_50, 15, 8);
    Set_Walls_Pos(Limit_51, 15, 9);
    Set_Walls_Pos(Limit_52, 15, 10);
}

void game::Create_Inside_Walls(){
    //Indestructible
    Put_Walls_Sprite(wall_1, 0, 0);
    Put_Walls_Sprite(wall_2, 0, 0);
    Put_Walls_Sprite(wall_3, 0, 0);
    Put_Walls_Sprite(wall_4, 0, 0);
    Put_Walls_Sprite(wall_5, 0, 0);
    Put_Walls_Sprite(wall_6, 0, 0);
    Put_Walls_Sprite(wall_7, 0, 0);
    Put_Walls_Sprite(wall_8, 0, 0);
    Put_Walls_Sprite(wall_9, 0, 0);
    Put_Walls_Sprite(wall_10, 0, 0);
    Put_Walls_Sprite(wall_11, 0, 0);
    Put_Walls_Sprite(wall_12, 0, 0);
    Put_Walls_Sprite(wall_13, 0, 0);
    Put_Walls_Sprite(wall_14, 0, 0);
    Put_Walls_Sprite(wall_15, 0, 0);
    Put_Walls_Sprite(wall_16, 0, 0);
    Put_Walls_Sprite(wall_17, 0, 0);
    Put_Walls_Sprite(wall_18, 0, 0);
    Put_Walls_Sprite(wall_19, 0, 0);
    Put_Walls_Sprite(wall_20, 0, 0);
    //Destructible
    Put_Walls_Sprite(wall_21, 1, 0);
    Put_Walls_Sprite(wall_22, 1, 0);
    Put_Walls_Sprite(wall_23, 1, 0);
    Put_Walls_Sprite(wall_24, 1, 0);
    Put_Walls_Sprite(wall_25, 1, 0);
    Put_Walls_Sprite(wall_26, 1, 0);
    Put_Walls_Sprite(wall_27, 1, 0);
    Put_Walls_Sprite(wall_28, 1, 0);
    Put_Walls_Sprite(wall_29, 1, 0);
    Put_Walls_Sprite(wall_30, 1, 0);
    Put_Walls_Sprite(wall_31, 1, 0);
    Put_Walls_Sprite(wall_32, 1, 0);
    Put_Walls_Sprite(wall_33, 1, 0);
    Put_Walls_Sprite(wall_34, 1, 0);
    Put_Walls_Sprite(wall_35, 1, 0);
    Put_Walls_Sprite(wall_36, 1, 0);
    Put_Walls_Sprite(wall_37, 1, 0);
    Put_Walls_Sprite(wall_38, 1, 0);
    Put_Walls_Sprite(wall_39, 1, 0);
    Put_Walls_Sprite(wall_40, 1, 0);

    Add_Inside_Walls_to_Scene();

    //Indestructible
    Set_Walls_Pos(wall_1, 2, 2);
    Set_Walls_Pos(wall_2, 4, 2);
    Set_Walls_Pos(wall_3, 6, 2);
    Set_Walls_Pos(wall_4, 8, 2);
    Set_Walls_Pos(wall_5, 10, 2);
    Set_Walls_Pos(wall_6, 12, 2);
    Set_Walls_Pos(wall_7, 14, 2);
    Set_Walls_Pos(wall_8, 3, 4);
    Set_Walls_Pos(wall_9, 5, 4);
    Set_Walls_Pos(wall_10, 7, 4);
    Set_Walls_Pos(wall_11, 9, 4);
    Set_Walls_Pos(wall_12, 11, 4);
    Set_Walls_Pos(wall_13, 13, 4);
    Set_Walls_Pos(wall_14, 15, 4);
    Set_Walls_Pos(wall_15, 1, 6);
    Set_Walls_Pos(wall_16, 1, 8);
    Set_Walls_Pos(wall_17, 4, 6);
    Set_Walls_Pos(wall_18, 4, 8);
    Set_Walls_Pos(wall_19, 7, 6);
    Set_Walls_Pos(wall_20, 7, 8);
    //Destructible
    Set_Walls_Pos(wall_21, 3, 3);
    Set_Walls_Pos(wall_22, 1, 3);
    Set_Walls_Pos(wall_23, 1, 4);
    Set_Walls_Pos(wall_24, 2, 5);
    Set_Walls_Pos(wall_25, 10, 6);
    Set_Walls_Pos(wall_26, 14, 9);
    Set_Walls_Pos(wall_27, 7, 3);
    Set_Walls_Pos(wall_28, 3, 7);
    Set_Walls_Pos(wall_29, 11, 2);
    Set_Walls_Pos(wall_30, 14, 1);
    Set_Walls_Pos(wall_31, 9, 2);
    Set_Walls_Pos(wall_32, 6, 6);
    Set_Walls_Pos(wall_33, 11, 10);
    Set_Walls_Pos(wall_34, 3, 9);
    Set_Walls_Pos(wall_35, 5, 10);
    Set_Walls_Pos(wall_36, 12, 8);
    Set_Walls_Pos(wall_37, 8, 6);
    Set_Walls_Pos(wall_38, 8, 7);
    Set_Walls_Pos(wall_39, 8, 9);
    Set_Walls_Pos(wall_40, 9, 9);
}

void game::Add_Limits_to_Scene()
{
    addItem(Limit_1);
    addItem(Limit_2);
    addItem(Limit_3);
    addItem(Limit_4);
    addItem(Limit_5);
    addItem(Limit_6);
    addItem(Limit_7);
    addItem(Limit_8);
    addItem(Limit_9);
    addItem(Limit_10);
    addItem(Limit_11);
    addItem(Limit_12);
    addItem(Limit_13);
    addItem(Limit_14);
    addItem(Limit_15);
    addItem(Limit_16);
    addItem(Limit_17);
    addItem(Limit_18);
    addItem(Limit_19);
    addItem(Limit_20);
    addItem(Limit_21);
    addItem(Limit_22);
    addItem(Limit_23);
    addItem(Limit_24);
    addItem(Limit_25);
    addItem(Limit_26);
    addItem(Limit_27);
    addItem(Limit_28);
    addItem(Limit_29);
    addItem(Limit_30);
    addItem(Limit_31);
    addItem(Limit_32);
    addItem(Limit_33);
    addItem(Limit_34);
    addItem(Limit_35);
    addItem(Limit_36);
    addItem(Limit_37);
    addItem(Limit_38);
    addItem(Limit_39);
    addItem(Limit_40);
    addItem(Limit_41);
    addItem(Limit_42);
    addItem(Limit_43);
    addItem(Limit_44);
    addItem(Limit_45);
    addItem(Limit_46);
    addItem(Limit_47);
    addItem(Limit_48);
    addItem(Limit_49);
    addItem(Limit_50);
    addItem(Limit_51);
    addItem(Limit_52);
}

void game::Add_Inside_Walls_to_Scene(){
    addItem(wall_1);
    addItem(wall_2);
    addItem(wall_3);
    addItem(wall_4);
    addItem(wall_5);
    addItem(wall_6);
    addItem(wall_7);
    addItem(wall_8);
    addItem(wall_9);
    addItem(wall_10);
    addItem(wall_11);
    addItem(wall_12);
    addItem(wall_13);
    addItem(wall_14);
    addItem(wall_15);
    addItem(wall_16);
    addItem(wall_17);
    addItem(wall_18);
    addItem(wall_19);
    addItem(wall_20);
    addItem(wall_21);
    addItem(wall_22);
    addItem(wall_23);
    addItem(wall_24);
    addItem(wall_25);
    addItem(wall_26);
    addItem(wall_27);
    addItem(wall_28);
    addItem(wall_29);
    addItem(wall_30);
    addItem(wall_31);
    addItem(wall_32);
    addItem(wall_33);
    addItem(wall_34);
    addItem(wall_35);
    addItem(wall_36);
    addItem(wall_37);
    addItem(wall_38);
    addItem(wall_39);
    addItem(wall_40);
}

void game::Create_Memory_Limits()
{
    Limit_1 = new Wall(0, 0, 0);
    Limit_2 = new Wall(0, 0, 0);
    Limit_3 = new Wall(0, 0, 0);
    Limit_4 = new Wall(0, 0, 0);
    Limit_5 = new Wall(0, 0, 0);
    Limit_6 = new Wall(0, 0, 0);
    Limit_7 = new Wall(0, 0, 0);
    Limit_8 = new Wall(0, 0, 0);
    Limit_9 = new Wall(0, 0, 0);
    Limit_10 = new Wall(0, 0, 0);
    Limit_11 = new Wall(0, 0, 0);
    Limit_12 = new Wall(0, 0, 0);
    Limit_13 = new Wall(0, 0, 0);
    Limit_14 = new Wall(0, 0, 0);
    Limit_15 = new Wall(0, 0, 0);
    Limit_16 = new Wall(0, 0, 0);
    Limit_17 = new Wall(0, 0, 0);
    Limit_18 = new Wall(0, 0, 0);
    Limit_19 = new Wall(0, 0, 0);
    Limit_20 = new Wall(0, 0, 0);
    Limit_21 = new Wall(0, 0, 0);
    Limit_22 = new Wall(0, 0, 0);
    Limit_23 = new Wall(0, 0, 0);
    Limit_24 = new Wall(0, 0, 0);
    Limit_25 = new Wall(0, 0, 0);
    Limit_26 = new Wall(0, 0, 0);
    Limit_27 = new Wall(0, 0, 0);
    Limit_28 = new Wall(0, 0, 0);
    Limit_29 = new Wall(0, 0, 0);
    Limit_30 = new Wall(0, 0, 0);
    Limit_31 = new Wall(0, 0, 0);
    Limit_32 = new Wall(0, 0, 0);
    Limit_33 = new Wall(0, 0, 0);
    Limit_34 = new Wall(0, 0, 0);
    Limit_35 = new Wall(0, 0, 0);
    Limit_36 = new Wall(0, 0, 0);
    Limit_37 = new Wall(0, 0, 0);
    Limit_38 = new Wall(0, 0, 0);
    Limit_39 = new Wall(0, 0, 0);
    Limit_40 = new Wall(0, 0, 0);
    Limit_41 = new Wall(0, 0, 0);
    Limit_42 = new Wall(0, 0, 0);
    Limit_43 = new Wall(0, 0, 0);
    Limit_44 = new Wall(0, 0, 0);
    Limit_45 = new Wall(0, 0, 0);
    Limit_46 = new Wall(0, 0, 0);
    Limit_47 = new Wall(0, 0, 0);
    Limit_48 = new Wall(0, 0, 0);
    Limit_49 = new Wall(0, 0, 0);
    Limit_50 = new Wall(0, 0, 0);
    Limit_50 = new Wall(0, 0, 0);
    Limit_51 = new Wall(0, 0, 0);
    Limit_52 = new Wall(0, 0, 0);
}

void game::Create_Memory_Walls(){
    //Indestructible
    wall_1 = new Wall(0, 0, 0);
    wall_2 = new Wall(0, 0, 0);
    wall_3 = new Wall(0, 0, 0);
    wall_4 = new Wall(0, 0, 0);
    wall_5 = new Wall(0, 0, 0);
    wall_6 = new Wall(0, 0, 0);
    wall_7 = new Wall(0, 0, 0);
    wall_8 = new Wall(0, 0, 0);
    wall_9 = new Wall(0, 0, 0);
    wall_10 = new Wall(0, 0, 0);
    wall_11 = new Wall(0, 0, 0);
    wall_12 = new Wall(0, 0, 0);
    wall_13 = new Wall(0, 0, 0);
    wall_14 = new Wall(0, 0, 0);
    wall_15 = new Wall(0, 0, 0);
    wall_16 = new Wall(0, 0, 0);
    wall_17 = new Wall(0, 0, 0);
    wall_18 = new Wall(0, 0, 0);
    wall_19 = new Wall(0, 0, 0);
    wall_20 = new Wall(0, 0, 0);
    //Destructible
    wall_21 = new Wall(0, 0, 1);
    wall_22 = new Wall(0, 0, 1);
    wall_23 = new Wall(0, 0, 1);
    wall_24 = new Wall(0, 0, 1);
    wall_25 = new Wall(0, 0, 1);
    wall_26 = new Wall(0, 0, 1);
    wall_27 = new Wall(0, 0, 1);
    wall_28 = new Wall(0, 0, 1);
    wall_29 = new Wall(0, 0, 1);
    wall_30 = new Wall(0, 0, 1);
    wall_31 = new Wall(0, 0, 1);
    wall_32 = new Wall(0, 0, 1);
    wall_33 = new Wall(0, 0, 1);
    wall_34 = new Wall(0, 0, 1);
    wall_35 = new Wall(0, 0, 1);
    wall_36 = new Wall(0, 0, 1);
    wall_37 = new Wall(0, 0, 1);
    wall_38 = new Wall(0, 0, 1);
    wall_39 = new Wall(0, 0, 1);
    wall_40 = new Wall(0, 0, 1);
}

void game::Delete_Memory_Walls(){
    delete wall_1;
    delete wall_2;
    delete wall_3;
    delete wall_4;
    delete wall_5;
    delete wall_6;
    delete wall_7;
    delete wall_8;
    delete wall_9;
    delete wall_10;
    delete wall_11;
    delete wall_12;
    delete wall_13;
    delete wall_14;
    delete wall_15;
    delete wall_16;
    delete wall_17;
    delete wall_18;
    delete wall_19;
    delete wall_20;
    delete wall_21;
    delete wall_22;
    delete wall_23;
    delete wall_24;
    delete wall_25;
    delete wall_26;
    delete wall_27;
    delete wall_28;
    delete wall_29;
    delete wall_30;
    delete wall_31;
    delete wall_32;
    delete wall_33;
    delete wall_34;
    delete wall_35;
    delete wall_36;
    delete wall_37;
    delete wall_38;
    delete wall_39;
    delete wall_40;
}

void game::Delete_Memory_Limits()
{
    delete Limit_1;
    delete Limit_2;
    delete Limit_3;
    delete Limit_4;
    delete Limit_5;
    delete Limit_6;
    delete Limit_7;
    delete Limit_8;
    delete Limit_9;
    delete Limit_10;
    delete Limit_11;
    delete Limit_12;
    delete Limit_13;
    delete Limit_14;
    delete Limit_15;
    delete Limit_16;
    delete Limit_17;
    delete Limit_18;
    delete Limit_19;
    delete Limit_20;
    delete Limit_21;
    delete Limit_22;
    delete Limit_23;
    delete Limit_24;
    delete Limit_25;
    delete Limit_26;
    delete Limit_27;
    delete Limit_28;
    delete Limit_29;
    delete Limit_30;
    delete Limit_31;
    delete Limit_32;
    delete Limit_33;
    delete Limit_34;
    delete Limit_35;
    delete Limit_36;
    delete Limit_37;
    delete Limit_38;
    delete Limit_39;
    delete Limit_40;
    delete Limit_41;
    delete Limit_42;
    delete Limit_43;
    delete Limit_44;
    delete Limit_45;
    delete Limit_46;
    delete Limit_47;
    delete Limit_48;
    delete Limit_49;
    delete Limit_50;
    delete Limit_51;
    delete Limit_52;
}
