
#ifndef WALL_H
#define WALL_H

#include "control_sprite.h"
#include "global_macros.h"

class Wall : public control_sprite
{
    Q_OBJECT
public:
    Wall(int xPos, int yPos, bool Destructible);
    ~Wall();

    void Set_Wall_Pos_x(int pos); //Wall position in y
    int Get_Wall_Pos_x(); //Wall position in y

    void Set_Wall_Pos_y(int pos); //Wall position in y
    int Get_Wall_Pos_y(); //Wall position in y

    void Set_Wall_Destructible(bool DoNd); //0:Indestructible, 1:Destructible
    bool Get_Wall_Destructible(); //0:Indestructible, 1:Destructible

    void Set_Wall_Exist(bool exist); //0:Doesn't Exist, 1:Exist
    bool Get_Wall_Exist(); //0:Doesn't Exist, 1:Exist
protected:
    int Wall_Pos_x; //Wall position in x
    int Wall_Pos_y; //Wall position in y
    bool *Wall_Destructible; //0:Indestructible, 1:Destructible
    bool *Wall_Exist; //0:Doesn't Exist, 1:Exist

    //Animations
    short Wall_Destruction_Actual_Frame; //private?
    short Wall_Destruction_Speed; //1000: 1 second
    QTimer *Wall_Time;
private slots:
    //Animations
    void Wall_Destruction_Animation();
};

#endif // WALL_H
