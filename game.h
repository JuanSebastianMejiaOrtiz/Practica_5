
#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "mainchar.h"
#include "wall.h"
#include "enemy.h"
#include "global_macros.h"

class game : public QGraphicsScene
{
public:
    game();
    ~game();

    void keyPressEvent(QKeyEvent *event);

    void Check_Collisions();

private:
    //Characters
        //Main Character
    mainchar *bomberman;

    void SetMC();

        //Enemy
    enemy *Enemy;

    void SetEnemy();


    //Walls
        //Limits
    Wall *Limit_1;
    Wall *Limit_2;
    Wall *Limit_3;
    Wall *Limit_4;
    Wall *Limit_5;
    Wall *Limit_6;
    Wall *Limit_7;
    Wall *Limit_8;
    Wall *Limit_9;
    Wall *Limit_10;
    Wall *Limit_11;
    Wall *Limit_12;
    Wall *Limit_13;
    Wall *Limit_14;
    Wall *Limit_15;
    Wall *Limit_16;
    Wall *Limit_17;
    Wall *Limit_18;
    Wall *Limit_19;
    Wall *Limit_20;
    Wall *Limit_21;
    Wall *Limit_22;
    Wall *Limit_23;
    Wall *Limit_24;
    Wall *Limit_25;
    Wall *Limit_26;
    Wall *Limit_27;
    Wall *Limit_28;
    Wall *Limit_29;
    Wall *Limit_30;
    Wall *Limit_31;
    Wall *Limit_32;
    Wall *Limit_33;
    Wall *Limit_34;
    Wall *Limit_35;
    Wall *Limit_36;
    Wall *Limit_37;
    Wall *Limit_38;
    Wall *Limit_39;
    Wall *Limit_40;
    Wall *Limit_41;
    Wall *Limit_42;
    Wall *Limit_43;
    Wall *Limit_44;
    Wall *Limit_45;
    Wall *Limit_46;
    Wall *Limit_47;
    Wall *Limit_48;
    Wall *Limit_49;
    Wall *Limit_50;
    Wall *Limit_51;
    Wall *Limit_52;
        //Inside Walls
    Wall *wall_1;
    Wall *wall_2;
    Wall *wall_3;
    Wall *wall_4;
    Wall *wall_5;
    Wall *wall_6;
    Wall *wall_7;
    Wall *wall_8;
    Wall *wall_9;
    Wall *wall_10;
    Wall *wall_11;
    Wall *wall_12;
    Wall *wall_13;
    Wall *wall_14;
    Wall *wall_15;
    Wall *wall_16;
    Wall *wall_17;
    Wall *wall_18;
    Wall *wall_19;
    Wall *wall_20;
    Wall *wall_21;
    Wall *wall_22;
    Wall *wall_23;
    Wall *wall_24;
    Wall *wall_25;
    Wall *wall_26;
    Wall *wall_27;
    Wall *wall_28;
    Wall *wall_29;
    Wall *wall_30;
    Wall *wall_31;
    Wall *wall_32;
    Wall *wall_33;
    Wall *wall_34;
    Wall *wall_35;
    Wall *wall_36;
    Wall *wall_37;
    Wall *wall_38;
    Wall *wall_39;
    Wall *wall_40;

        //Create Memory Walls
    void Create_Memory_Limits();
    void Create_Memory_Walls();
        //Delete Memory Walls
    void Delete_Memory_Limits();
    void Delete_Memory_Walls();
        //Set Walls
    void SetWalls();

    void Put_Walls_Sprite(Wall *Wall, int sprite_x, int sprite_y);
    void Set_Walls_Pos(Wall *Wall, int posx, int posy);

    void Create_Limits();
    void Add_Limits_to_Scene();

    void Create_Inside_Walls();
    void Add_Inside_Walls_to_Scene();


    //Collisions
        //Walls with Characters
    void Walls_with_character(Character *chara);
        //Walls with Bombs
    void Walls_with_bomb(bomb *boom);
    void bomb_not_throught_walls(bomb *boom);
    void Walls_with_explosion(bomb *boom);


};

#endif // GAME_H
