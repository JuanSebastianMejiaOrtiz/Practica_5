
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
    delete paredes;
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

    for (std::vector<Wall>::iterator ite = paredes->begin(); ite != paredes->end(); ite++){
        if (ite->Get_Wall_Destructible()){
            ite->Select_sprite(1, 0);
            ite->Scale_sprite(Scale);
            ite->Show_Sprite(1);
        }
        else{
            ite->Select_sprite(0, 0);
            ite->Scale_sprite(Scale);
            ite->Show_Sprite(1);
        }
    }
}

void game::Create_Limits()
{
    for (int i = 0; i < (Limits_Wall_Quantity_x + Limits_Wall_Quantity_y - 1); i++){
        Wall muro(0, 0, 0);
        paredes->push_back(muro);
    }

    Set_Limits_Pos();
}

void game::Set_Limits_Pos()
{
    int i = 0;
    int pos = 0;
    std::vector<Wall>::iterator ite = paredes->begin();

    for (; i < (Limits_Wall_Quantity_x/2); i++){
        //Separacion
        (ite + i)->Set_Wall_Pos_x(pos * wall_ancho);
    }

    for (pos = 0; i < Limits_Wall_Quantity_x; i++, pos++){
        //Separacion
        (ite + i)->Set_Wall_Pos_x(pos * wall_ancho);
        (ite + i)->Set_Wall_Pos_y((wall_alto * Limits_Wall_Quantity_y/2) - wall_alto);
    }

    for (pos = 0; i < (Limits_Wall_Quantity_x + (Limits_Wall_Quantity_y/2)); i++, pos++){
        //Separacion
        (ite + i)->Set_Wall_Pos_x((wall_ancho * (Limits_Wall_Quantity_x/2)) - wall_ancho);
        (ite + i)->Set_Wall_Pos_y(pos * wall_alto);
    }

    for (pos = 0; i < (Limits_Wall_Quantity_x + Limits_Wall_Quantity_y); i++, pos++){
        //Separacion
        (ite + i)->Set_Wall_Pos_y(pos * wall_alto);
    }
}
