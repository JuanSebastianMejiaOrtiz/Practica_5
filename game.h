
#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

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
    Wall *pared;
};

#endif // GAME_H
