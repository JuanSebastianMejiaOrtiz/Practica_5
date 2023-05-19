
#ifndef ENEMY_H
#define ENEMY_H

#include <cstdlib>
#include <ctime>

#include "character.h"
#include "global_macros.h"

class enemy : public Character
{
public:
    enemy();
    ~enemy();

    void Set_Direction();

protected:
    QTimer Dead_Timer;

private:
    int Enemy_Dead_Actual_Frame;

private slots:
    //Dead Animation
    void Dead_Animation();
};

#endif // ENEMY_H
