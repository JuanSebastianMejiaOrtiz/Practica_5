
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

private:
    //Position
    int *Bomb_pos_x;
    int *Bomb_pos_y;

    //Animation Atributes
        //Dudas de si es necesario
    bool adjust_size_sprite;
        //Both
    bool kaboom; //0:no explosion, 1:explosion
    QTimer *bomb_timer;
    int Bomb_Animation_Speed; //1000: 1 second
    int Bomb_Animation_Actual_Frame;
        //Bomb
    short Bomb_Animation_Moving_Repeat;
        //Explosion
    bool end_explosion;
    int explosion_y;
    int explosion_x;
    bool change_line;
    QPixmap *Temp_Full;

    //Other
    bool *Already_Exist;

    //Animation Methods
    void Boom();
    void Plant_Bomb();
    void kaboom1();
    void kaboom2();

private slots:
    //Animation Explosion
    void Kaboom();
    void Bomb_Moving();
};

#endif // BOMB_H
