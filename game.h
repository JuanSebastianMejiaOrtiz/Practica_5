
#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>

#include "mainchar.h"

class game : public QGraphicsScene
{
public:
    game();

private:
    mainchar *bomberman;
};

#endif // GAME_H
