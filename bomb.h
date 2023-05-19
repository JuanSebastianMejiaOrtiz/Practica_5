
#ifndef BOMB_H
#define BOMB_H

#include "control_sprite.h"
#include "global_macros.h"

class bomb : public control_sprite
{
    Q_OBJECT
public:
    bomb();
    ~bomb();

    //Set and Get Methods
        //kaboom
    void Set_kaboom(bool boom);
    bool Get_kaboom();
        //Already_Exist
    void Set_Already_Exist(bool exist);
    bool Get_Already_Exist();
        //Bomb_pos_x
    void Set_Bomb_pos_x(int x);
    int Get_Bomb_pos_x();
        //Bomb_pos_y
    void Set_Bomb_pos_y(int y);
    int Get_Bomb_pos_y();

    void Set_Default_Values();

    QTimer *Bomb_Cooldown;
    QTimer *bomb_timer;

private:
    //Position
    int *Bomb_pos_x;
    int *Bomb_pos_y;

    //Animation Atributes
        //Both
    bool kaboom; //0:no explosion, 1:explosion
    int Bomb_Animation_Speed; //1000: 1 second
    int Bomb_Animation_Actual_Frame;
        //Explosion
    int explosion_y;
    int explosion_x;
    QPixmap *Explosions;

    //Other
    bool *Already_Exist;

    //Animation Methods
    void Plant_Bomb();
    void kaboom1();

    //Method for sprites
    void Explosion_Select_Sprite(int _x, int _y);

private slots:
    //Animation Explosion
    void Bomb_Animations();
    void Bomb_Check_If_Can_Use();
};

#endif // BOMB_H
