
#ifndef WALL_H
#define WALL_H

#include "control_sprite.h"
#include "global_macros.h"

class Wall : public control_sprite
{
public:
    Wall(int xPos, int yPos, bool Destructible);
    ~Wall();

    void Set_Wall_Pos_x(int pos);
    int Get_Wall_Pos_x();

    void Set_Wall_Pos_y(int pos);
    int Get_Wall_Pos_y();

    void Set_Wall_Destructible(bool DoNd);
    bool Get_Wall_Destructible();

    void Wall_Destruction_Animation();
protected:
    int *Wall_Pos_x;
    int *Wall_Pos_y;
    bool *Wall_Destructible;

    //Animations
    short Wall_Destruction_Actual_Frame;
    short Wall_Destruction_Speed;
    QTimer *Wall_Time;
};

#endif // WALL_H
