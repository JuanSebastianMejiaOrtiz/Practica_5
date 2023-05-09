
#ifndef CHARACTER_H
#define CHARACTER_H

#include "control_sprite.h"
#include <QGraphicsPixmapItem>

#define Walk_Velocity 10
#define Walk_Animation_Velocity 4
#define Ammount_of_Frames_Walk 3

class Character : protected control_sprite
{
    Q_OBJECT
public:
    Character(int Start_Point_x, int Start_Point_y);
    ~Character();

    //Movement
    void Movement();
private:
    int Movement_Speed;
    int *Pos_x;
    int *Pos_y;
    char *direction;

    short Walk_Animation_Speed;
    short Walk_Animation_Frame_Ammount;

    QTimer *time;
private slots:
    //Walk Animation
    void Walk_Up_Animation();
    void Walk_Down_Animation();
    void Walk_Left_Animation();
    void Walk_Right_Animation();
};

#endif // CHARACTER_H
