
#ifndef ENEMY_H
#define ENEMY_H

#include <random>

#include "character.h"
#include "global_macros.h"

class enemy : public Character
{
public:
    enemy();
    ~enemy();

protected:
    QTimer *Dead_Timer;

private:
    int Enemy_Dead_Actual_Frame;
    QTimer *Move_Timer;

private slots:
    //Position
    void Enemy_Set_Direction();

    //Dead Animation
    void Dead_Animation();
};

#endif // ENEMY_H
