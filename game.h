
#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "mainchar.h"
#include "global_maincharacter.h"

class game : public QGraphicsScene
{
public:
    game();
    ~game();

    void keyPressEvent(QKeyEvent *event);

private:
    mainchar *bomberman;
};

#endif // GAME_H
