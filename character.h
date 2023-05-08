
#ifndef CHARACTER_H
#define CHARACTER_H

#include "control_sprite.h"
#include <QGraphicsPixmapItem>

#define Walk_Velocity 10
#define Walk_Animation_Velocity 4
#define Start_Point_x 0
#define Start_Point_y 0

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
    int *Pos_x;
    int *Pos_y;
};

#endif // CHARACTER_H
