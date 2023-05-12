
#include "game.h"

game::game()
{
    bomberman = new mainchar();
    addItem(bomberman->mc);
}

game::~game()
{
    delete bomberman;
}

