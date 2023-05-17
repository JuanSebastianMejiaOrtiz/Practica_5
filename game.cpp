
#include "game.h"

game::game()
{
    bomberman = new mainchar();
    pared = new Wall(0,1,0);

    //Set Bomberman
    bomberman->Select_sprite(4, 0);
    bomberman->Scale_sprite(Scale);
    bomberman->Show_Sprite(1);

    //Set Pared
    pared->Select_sprite(3, 0);
    pared->Scale_sprite(Scale);
    pared->Show_Sprite(1);
    pared->setPos(pared->Get_Wall_Pos_x(), pared->Get_Wall_Pos_y());

    //Add Items
    addItem(bomberman);
    addItem(pared);
}

game::~game()
{
    delete bomberman;
}

void game::keyPressEvent(QKeyEvent *event)
{
    bomberman->keyPressEvent(event);
}

