
#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <string>

#include "mainchar.h"
#include "wall.h"
#include "enemy.h"
#include "global_macros.h"

class game : public QGraphicsScene
{
    Q_OBJECT
public:
    game();
    ~game();

    void keyPressEvent(QKeyEvent *event);

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
    Wall *Limits[Number_of_Limits];
        //Inside Walls
    Wall *Inside_Walls[Number_of_Inside_Walls];

        //Set Walls
    void SetWalls();

    void Put_Walls_Sprite(Wall *Wall, int sprite_x, int sprite_y);
    void Set_Walls_Pos(Wall *Wall, int posx, int posy);

    void Create_Limits();
    void Add_Limits_to_Scene();

    void Create_Inside_Walls();
    void Add_Inside_Walls_to_Scene();
    void set_fondo();


    //Collisions
        //Attributes
    QTimer *Checking;
        //Walls with Characters
    void Walls_with_character(Character *chara, Wall *muro);
        //Enemy with Character
    void Enemy_and_Main_Character(Character *chara, enemy *villian);
        //Bomb Explosion
    //void bomb_not_throught_walls(bomb *boom);
    //void Walls_with_explosion(bomb *boom);

    void Check_with_mc();
    void Check_with_enemy();

private slots:
    //Collisions
    void Check_Collisions();
    void poner_bomba(QGraphicsItem *item);

};

#endif // GAME_H
