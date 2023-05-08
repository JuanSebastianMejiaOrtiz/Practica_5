
#ifndef CHARACTER_H
#define CHARACTER_H

#include "control_sprite.h"

class Character : protected control_sprite
{
public:
    Character();

    void Walk_Up_Animation();
    void Walk_Down_Animation();
    void Walk_Left_Animation();
    void Walk_Right_Animation();

    void Movement(char *direction);
    void Move(char *direction);
private:
    float Movement_Speed;
    int Walk_Animation_Speed;
};

#endif // CHARACTER_H
