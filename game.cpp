
#include "game.h"

game::game()
{
    //Asignar memoria
    bomberman = new mainchar();

    //pared = new Wall(0,1,0);

    //Set and Add Items
    SetMC();
    //SetWalls();
}

game::~game()
{
    delete bomberman;

}

void game::keyPressEvent(QKeyEvent *event)
{
    bomberman->keyPressEvent(event);
}

void game::SetMC()
{
    //Set Bomberman
    bomberman->Select_sprite(4, 0);
    bomberman->Scale_sprite(Scale);
    bomberman->Show_Sprite(1);
    addItem(bomberman);
    bomberman->setPos(QPointF(pos_x_initial_mc, pos_y_initial_mc));
}

void game::SetWalls()
{
    //Set Pared
    //pared->Select_sprite(1, 0);
    //pared->Scale_sprite(Scale);
    //pared->Show_Sprite(1);
    //pared->setPos(pared->Get_Wall_Pos_x(), pared->Get_Wall_Pos_y());

    Create_Limits();


}

void game::Create_Limits()
{

}

void game::Set_Limits_Pos()
{

}
