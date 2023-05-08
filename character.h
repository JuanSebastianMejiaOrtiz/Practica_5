
#ifndef CHARACTER_H
#define CHARACTER_H

#include "control_sprite.h"

class Character : protected control_sprite
{
public:
    Character();

    //Walk Animation
    void Walk_Up_Animation();
    void Walk_Down_Animation();
    void Walk_Left_Animation();
    void Walk_Right_Animation();

    //Movement
    void Movement(char *direction);
private:
    float Movement_Speed;
    int Walk_Animation_Speed;
    int *Pos_x = 0, *Pos_y = 0;
};

#endif // CHARACTER_H
