
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

    void Set_Direction(char car);
    char Get_Direction();

    void Set_Pos_x(int new_pos);
    int Get_Pos_x();

    void Set_Pos_y(int new_pos);
    int Get_Pos_y();

    void Set_Walk_Animation_Speed(short speed);
    short Get_Walk_Animation_Speed();

    void Set_isMoving(bool VoF);
    bool Get_isMoving();

protected:
    //Position Variables
    int Movement_Speed;
    int *Pos_x;
    int *Pos_y;
    char *direction;
    bool *isMoving;

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
