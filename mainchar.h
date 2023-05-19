
#ifndef MAINCHAR_H
#define MAINCHAR_H

#include <QKeyEvent>

#include "character.h"
#include "bomb.h"
#include "global_macros.h"

class mainchar : public Character
{
    Q_OBJECT
public:
    mainchar();
    ~mainchar();

    //Inputs
    void keyPressEvent(QKeyEvent *event);

    //Bomb
    bomb *bomba;

protected:
    //Dead_Animation
    QTimer *Dead_Timer;

private:
    //Dead_Animation
    int *Dead_Actual_Frame;

private slots:
    //Dead Animation
    void Dead_Animation();
};

#endif // MAINCHAR_H
