
#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <vector>

#include "mainchar.h"
#include "wall.h"
#include "global_macros.h"

class game : public QGraphicsScene
{
public:
    game();
    ~game();

    void keyPressEvent(QKeyEvent *event);

private:
    mainchar *bomberman;

    //Muros
        //Limites
    Wall *Limit_1;
    Wall *Limit_2;
    Wall *Limit_3;
    Wall *Limit_4;
    Wall *Limit_5;
    Wall *Limit_6;
    Wall *Limit_7;
    Wall *Limit_8;
    Wall *Limit_9;
    Wall *Limit_10;
    Wall *Limit_11;
    Wall *Limit_12;
    Wall *Limit_13;
    Wall *Limit_14;
    Wall *Limit_15;
    Wall *Limit_16;
    Wall *Limit_17;
    Wall *Limit_18;
    Wall *Limit_19;
    Wall *Limit_20;
    Wall *Limit_21;
    Wall *Limit_22;
    Wall *Limit_23;
    Wall *Limit_24;
    Wall *Limit_25;
    Wall *Limit_26;
    Wall *Limit_27;
    Wall *Limit_28;
    Wall *Limit_29;
    Wall *Limit_30;
    Wall *Limit_31;
    Wall *Limit_32;
    Wall *Limit_33;
    Wall *Limit_34;
    Wall *Limit_35;
    Wall *Limit_36;
    Wall *Limit_37;
    Wall *Limit_38;
    Wall *Limit_39;
    Wall *Limit_40;
    Wall *Limit_41;
    Wall *Limit_42;
    Wall *Limit_43;
    Wall *Limit_44;
    Wall *Limit_45;
    Wall *Limit_46;
    Wall *Limit_47;
    Wall *Limit_48;
    Wall *Limit_49;
    Wall *Limit_50;


    void SetMC();
    void SetWalls();

    void Fill_Paredes(bool destructible);
    void Create_Limits();
    void Set_Limits_Pos();

};

#endif // GAME_H
