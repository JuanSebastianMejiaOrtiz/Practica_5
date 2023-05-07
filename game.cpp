
#include "game.h"

game::game()
{
    bomberman = new mainchar(0,0,100,100);
    addItem(bomberman);
}

