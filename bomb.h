
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
        //Already_Exist
    void Set_Already_Exist(bool exist);
    bool Get_Already_Exist();

    void Set_Default_Values();
    bool is_activated();
    void activate_bomb(bool act);

    QTimer *Bomb_Detonate;
    QTimer *bomb_timer;

    //Position
    QPointF Pos_Bomb;

private:
    //Attributes
        //Animation
            //Plant bomb
    short contador_bomb;
    int Bomb_Animation_Speed; //1000: 1 second
    int Bomb_Animation_Actual_Frame;
            //Explosion
    int explosion_y;
    int explosion_x;
    QPixmap *Full_Explosions;

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

signals:
    void start_explosion(QTimer *timer);
    void end_explosion();
};

#endif // BOMB_H
