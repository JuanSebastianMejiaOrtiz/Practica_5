
#ifndef MAINCHAR_H
#define MAINCHAR_H

#include <QKeyEvent>

#include "character.h"
#include "global_maincharacter.h"

class mainchar
{
public:
    mainchar();
    ~mainchar();

    Character *mc;

    //Dead Animation
    void Dead_Animation();
    //Inputs
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    //Bomba
};

#endif // MAINCHAR_H
