
#include "game.h"

game::game()
{
    bomberman = new mainchar();
    addItem(bomberman);
    bomberman->Show_Sprite(1);
    bomberman->setPos(0,0);
}

game::~game()
{
    delete bomberman;
}

