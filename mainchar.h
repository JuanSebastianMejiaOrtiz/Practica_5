
#ifndef MAINCHAR_H
#define MAINCHAR_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include "character.h"

#define alto_mainchar 16
#define ancho_mainchar 16
#define pos_x_initial 0
#define pos_y_initial 0

class mainchar
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
private:
    Character *mc;
};

#endif // MAINCHAR_H
