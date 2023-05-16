
#ifndef MAINCHAR_H
#define MAINCHAR_H

#include <QKeyEvent>

#include "character.h"
#include "global_macros.h"

class mainchar : public Character
{
public:
    mainchar();
    ~mainchar();

    //Dead Animation
    void Dead_Animation();
    //Inputs
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    //Bomba
};

#endif // MAINCHAR_H
