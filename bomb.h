
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
    //void Set_kaboom(bool boom);
    //bool Get_kaboom();
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
    bool is_activated();
    void activate_bomb(bool act);

    QTimer *Bomb_Detonate;
    QTimer *bomb_timer;

private:
    //Attributes
        //Position
    int *Bomb_pos_x;
    int *Bomb_pos_y;

        //Animation
            //Plant bomb
    short contador_bomb;
    int Bomb_Animation_Speed; //1000: 1 second
    int Bomb_Animation_Actual_Frame;
            //Explosion
    int explosion_y;
    int explosion_x;
    QPixmap *Full_Explosions;
    //Array Explosions:
        // 0:center
        // 1:up end
        // 2:down end
        // 3:left end
        // 4:right end
    QPixmap *Explosions[5];

    //Other
    bool is_active;

    //Animation Methods
    void Plant_Bomb();
    void kaboom1();

    //Method for sprites
    void Explosion_Select_Sprite(int _x, int _y);

private slots:
    //Animation Explosion
    void Bomb_Plant_Animation();
    void Bomb_Explosion_Animation();
};

#endif // BOMB_H
