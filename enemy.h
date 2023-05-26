
#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "global_macros.h"
#include <cstdlib>
#include <ctime>

class enemy : public Character
{
    Q_OBJECT
public:
    enemy();
    ~enemy();

protected:
    //Movement
    void Enemy_Movement();
    //Animations
    QTimer *Dead_Timer;
    void Enemy_Animation();
    void Enemy_Animation_Left();
    void Enemy_Animation_Right();

private:
    int Enemy_Dead_Actual_Frame;
    QTimer *Enemy_Move_Timer;
    QTimer *Change_Move_Timer;

private slots:
    //Position
    void Enemy_Set_Direction();
    void Enemy_Move();

    //Dead Animation
    void Dead_Animation();
};

#endif // ENEMY_H
