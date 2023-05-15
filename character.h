
#ifndef CHARACTER_H
#define CHARACTER_H

#include "control_sprite.h"
#include "global_maincharacter.h"

class Character : public control_sprite
{
    Q_OBJECT
public:
    Character(int Start_Point_x, int Start_Point_y);
    ~Character();

    //Movement
    void Movement();
    void Move();

private:
    //Position Variables
    int Movement_Speed;
    int *Pos_x;
    int *Pos_y;
    char *direction;

    //Animation Variables
    short Walk_Animation_Speed;
    short Walk_Animation_Actual_Frame;

    QTimer *timer;

    void Walk_Up_Animation();
    void Walk_Down_Animation();
    void Walk_Left_Animation();
    void Walk_Right_Animation();

private slots:
    //Animations
    void Walk_Animation();

};

#endif // CHARACTER_H
