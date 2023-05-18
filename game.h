
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
    std::vector<Wall> *paredes;

    void SetMC();
    void SetWalls();

    void Fill_Paredes(bool destructible);
    void Create_Limits();
    void Set_Limits_Pos();

};

#endif // GAME_H
