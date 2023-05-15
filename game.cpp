
#include "game.h"

game::game()
{
    bomberman = new mainchar();
    addItem(bomberman->mc);
    bomberman->mc->setPixmap(*(bomberman->mc->actual));
}

game::~game()
{
    delete bomberman;
}

