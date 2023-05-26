
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
    int i;
            //Limits
    for (i = 0; i < Number_of_Limits; i++){
        Limits[i] = new Wall(0, 0, 0);
    }
            //Inside Walls
    for (i = 0; i < Number_of_Inside_Walls; i++){
        Inside_Walls[i] = new Wall(0, 0, 0);
    }
        //Collisions
    Checking = new QTimer;


    //Set and Add Items
    SetMC();
    SetEnemy();
    SetWalls();
    set_fondo();

    //Connect for all signals
        //Connect and Start Timer
    connect(Checking, SIGNAL(timeout()), this, SLOT(Check_Collisions()));
    Checking->start(Check);
        //Connect Colocar Bomba
    connect(bomberman, SIGNAL(colocar_bomba(QGraphicsItem*)), this, SLOT(poner_bomba(QGraphicsItem*)));
    connect(bomberman, SIGNAL(quita_bomba(QTimer*)), this, SLOT(quitar_bomba(QTimer*)));
    connect(bomberman, SIGNAL(end_explosion(QGraphicsItem*)), this, SLOT(Fin_Explosion(QGraphicsItem*)));
}

game::~game()
{
    delete Checking;
    delete bomberman;
    delete Enemy;
    //Walls
        //Limits
    int i;
    for (i = 0; i < Number_of_Limits; i++){
        delete Limits[i];
    }
        //Inside Walls
    for (i = 0; i < Number_of_Inside_Walls; i++){
        delete Inside_Walls[i];
    }

}

void game::keyPressEvent(QKeyEvent *event)
{
    bomberman->keyPressEvent(event);
}

void game::Check_Collisions()
{
    Check_with_mc();
    Check_with_enemy();
}

void game::poner_bomba(QGraphicsItem *item)
{
    addItem(item);
}

void game::quitar_bomba(QTimer *timer){
    timer->start(explosion_Animation_Speed);
}

void game::Fin_Explosion(QGraphicsItem *item)
{
    removeItem(item);
}

void game::Check_with_mc(){
    //With Walls
        //Limits
    int i;
    for (i = 0; i < Number_of_Limits; i++){
    Walls_with_character(bomberman, Limits[i]);
    }
        //Inside Walls
    for (i = 0; i < Number_of_Inside_Walls; i++){
        Walls_with_character(bomberman, Inside_Walls[i]);
    }
    
    //Collides with enemies
    Enemy_and_Main_Character(bomberman, Enemy);
}

void game::Check_with_enemy(){
    int i;
    //With Walls
    //Limits
    for (i = 0; i < Number_of_Limits; i++){
        Walls_with_character(Enemy, Limits[i]);
    }
        //Inside Walls
    for (i = 0; i < Number_of_Inside_Walls; i++){
        Walls_with_character(Enemy, Inside_Walls[i]);
    }
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
            chara->Set_Direction('n');
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
    int i, pos;
    //Put Limits
    for (i = 0; i < Number_of_Limits; i++){
        Put_Walls_Sprite(Limits[i], 0, 0);
    }

    //Add Limits to Scene
    Add_Limits_to_Scene();

    //Set Limits
        //Eje x
    for (i = 0, pos = 0; i < Number_Limits_x_One_side; i++, pos++){
        Set_Walls_Pos(Limits[i], pos, 0);
    }
    for (pos = 0; i < (Number_Limits_x_One_side * 2); i++, pos++){
        Set_Walls_Pos(Limits[i], pos, Number_Limits_y_One_side+1);
    }

        //Eje y
    for (pos = 1; i < ((Number_Limits_x_One_side * 2) + Number_Limits_y_One_side); pos++, i++){
        Set_Walls_Pos(Limits[i], 0, pos);
    }
    for (pos = 1; i < ((Number_Limits_x_One_side * 2) + (Number_Limits_y_One_side * 2)); pos++, i++){
        Set_Walls_Pos(Limits[i], Number_Limits_x_One_side-1, pos);
    }
}

void game::Create_Inside_Walls(){
    int i, pos_in_x, pos_in_y;
    //Indestructible
    for (i = 0; i < Number_of_Inside_Walls/2; i++){
        Put_Walls_Sprite(Inside_Walls[i], 0, 0);
    }
    //Destructible
    for (; i < Number_of_Inside_Walls; i++){
        Put_Walls_Sprite(Inside_Walls[i], 1, 0);
    }

    Add_Inside_Walls_to_Scene();

    //Indestructible
    for (i = 0, pos_in_x = 2, pos_in_y = 2; i < 7; i++, pos_in_x += 2){
        Set_Walls_Pos(Inside_Walls[i], pos_in_x, pos_in_y);
    }
    for (pos_in_x = 3, pos_in_y = 4; i < 7+7; i++, pos_in_x += 2){
        Set_Walls_Pos(Inside_Walls[i], pos_in_x, pos_in_y);
    }
    for (pos_in_x = 1, pos_in_y = 6; i < 7+7+3; i++, pos_in_x += 3){
        Set_Walls_Pos(Inside_Walls[i], pos_in_x, pos_in_y);
    }
    for (pos_in_x = 1, pos_in_y = 8; i < 7+7+3+3; i++, pos_in_x += 3){
        Set_Walls_Pos(Inside_Walls[i], pos_in_x, pos_in_y);
    }
    //Destructible
    Set_Walls_Pos(Inside_Walls[i++], 1, 3);
    Set_Walls_Pos(Inside_Walls[i++], 1, 4);
    Set_Walls_Pos(Inside_Walls[i++], 2, 5);
    Set_Walls_Pos(Inside_Walls[i++], 3, 3);
    Set_Walls_Pos(Inside_Walls[i++], 3, 7);
    Set_Walls_Pos(Inside_Walls[i++], 3, 9);
    Set_Walls_Pos(Inside_Walls[i++], 5, 10);
    Set_Walls_Pos(Inside_Walls[i++], 6, 6);
    Set_Walls_Pos(Inside_Walls[i++], 7, 3);
    Set_Walls_Pos(Inside_Walls[i++], 8, 6);
    Set_Walls_Pos(Inside_Walls[i++], 8, 7);
    Set_Walls_Pos(Inside_Walls[i++], 8, 9);
    Set_Walls_Pos(Inside_Walls[i++], 9, 2);
    Set_Walls_Pos(Inside_Walls[i++], 9, 9);
    Set_Walls_Pos(Inside_Walls[i++], 10, 6);
    Set_Walls_Pos(Inside_Walls[i++], 11, 2);
    Set_Walls_Pos(Inside_Walls[i++], 11, 10);
    Set_Walls_Pos(Inside_Walls[i++], 12, 8);
    Set_Walls_Pos(Inside_Walls[i++], 14, 1);
    Set_Walls_Pos(Inside_Walls[i++], 14, 9);
}

void game::Add_Limits_to_Scene()
{
    for (int i = 0; i < Number_of_Limits; i++){
        addItem(Limits[i]);
    }
}

void game::Add_Inside_Walls_to_Scene(){
    for (int i = 0; i < Number_of_Inside_Walls; i++){
        addItem(Inside_Walls[i]);
    }
}

void game::set_fondo()
{
    QImage img(":/Recursos/Practica5_sprites.png");
    QBrush br;

    img = img.copy(160,0,1,1);
    br.setTextureImage(img);
    setBackgroundBrush(br);
}

