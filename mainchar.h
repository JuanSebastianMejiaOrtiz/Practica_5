
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
    QTimer Dead_Timer;

private:
    //Dead_Animation
    int Dead_Actual_Frame;

    int setPosBomb(int pos, bool xoy); //0:ancho, 1:alto

    QPointF Position_Bomb();

private slots:
    //Dead Animation
    void Dead_Animation();

    void Quit_Bomb(QTimer *timer);

    void End_Bomb();

signals:
    void colocar_bomba(QGraphicsItem *item);

    void quita_bomba(QTimer *timer);

    void end_explosion(QGraphicsItem *item);
};

#endif // MAINCHAR_H
