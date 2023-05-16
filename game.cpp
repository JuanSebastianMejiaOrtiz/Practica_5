
#include "game.h"

game::game()
{
    bomberman = new mainchar();
    bomberman->Select_sprite(4, 0);
    bomberman->Scale_sprite(Scale);
    bomberman->Show_Sprite(1);
    bomberman->setPos(pos_x_initial, pos_y_initial);
    addItem(bomberman);
}

game::~game()
{
    delete bomberman;
}

void game::keyPressEvent(QKeyEvent *event)
{
    bomberman->keyPressEvent(event);
}

