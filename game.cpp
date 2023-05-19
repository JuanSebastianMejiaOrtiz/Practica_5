
#include "game.h"

game::game()
{
    //Asignar memoria
    bomberman = new mainchar();
        //Walls
    Create_Memory_Limits();

    //Set and Add Items
    SetMC();
    SetWalls();
}

game::~game()
{
    delete bomberman;
    //Walls
        //Limits
    Delete_Memory_Limits();

}

void game::keyPressEvent(QKeyEvent *event)
{
    bomberman->keyPressEvent(event);
    if (bomberman->bomba->Get_Already_Exist() && (!(bomberman->bomba->isActive()))){
        addItem(bomberman->bomba);
    }
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
    Create_Limits();
}


//Walls
void game::Put_Walls_Sprite(Wall *Wall, int sprite_x, int sprite_y)
{
    Wall->Select_sprite(sprite_x, sprite_y);
    Wall->Scale_sprite(Scale);
    Wall->Show_Sprite(1);
}

void game::Set_Walls_Pos(Wall *Wall, int posx, int posy)
{
    int x = posx * wall_ancho * Scale;
    int y = posy * wall_alto * Scale;

    Wall->Set_Wall_Pos_x(x);
    Wall->Set_Wall_Pos_y(y);
    Wall->setPos(QPointF(Wall->Get_Wall_Pos_x(), Wall->Get_Wall_Pos_y()));
}

void game::Create_Limits()
{
    //Put Limits
    Put_Walls_Sprite(Limit_1, 0, 0);
    Put_Walls_Sprite(Limit_2, 0, 0);
    Put_Walls_Sprite(Limit_3, 0, 0);
    Put_Walls_Sprite(Limit_4, 0, 0);
    Put_Walls_Sprite(Limit_5, 0, 0);
    Put_Walls_Sprite(Limit_6, 0, 0);
    Put_Walls_Sprite(Limit_7, 0, 0);
    Put_Walls_Sprite(Limit_8, 0, 0);
    Put_Walls_Sprite(Limit_9, 0, 0);
    Put_Walls_Sprite(Limit_10, 0, 0);
    Put_Walls_Sprite(Limit_11, 0, 0);
    Put_Walls_Sprite(Limit_12, 0, 0);
    Put_Walls_Sprite(Limit_13, 0, 0);
    Put_Walls_Sprite(Limit_14, 0, 0);
    Put_Walls_Sprite(Limit_15, 0, 0);
    Put_Walls_Sprite(Limit_16, 0, 0);
    Put_Walls_Sprite(Limit_17, 0, 0);
    Put_Walls_Sprite(Limit_18, 0, 0);
    Put_Walls_Sprite(Limit_19, 0, 0);
    Put_Walls_Sprite(Limit_20, 0, 0);
    Put_Walls_Sprite(Limit_21, 0, 0);
    Put_Walls_Sprite(Limit_22, 0, 0);
    Put_Walls_Sprite(Limit_23, 0, 0);
    Put_Walls_Sprite(Limit_24, 0, 0);
    Put_Walls_Sprite(Limit_25, 0, 0);
    Put_Walls_Sprite(Limit_26, 0, 0);
    Put_Walls_Sprite(Limit_27, 0, 0);
    Put_Walls_Sprite(Limit_28, 0, 0);
    Put_Walls_Sprite(Limit_29, 0, 0);
    Put_Walls_Sprite(Limit_30, 0, 0);
    Put_Walls_Sprite(Limit_31, 0, 0);
    Put_Walls_Sprite(Limit_32, 0, 0);
    Put_Walls_Sprite(Limit_33, 0, 0);
    Put_Walls_Sprite(Limit_34, 0, 0);
    Put_Walls_Sprite(Limit_35, 0, 0);
    Put_Walls_Sprite(Limit_36, 0, 0);
    Put_Walls_Sprite(Limit_37, 0, 0);
    Put_Walls_Sprite(Limit_38, 0, 0);
    Put_Walls_Sprite(Limit_39, 0, 0);
    Put_Walls_Sprite(Limit_40, 0, 0);
    Put_Walls_Sprite(Limit_41, 0, 0);
    Put_Walls_Sprite(Limit_42, 0, 0);
    Put_Walls_Sprite(Limit_43, 0, 0);
    Put_Walls_Sprite(Limit_44, 0, 0);
    Put_Walls_Sprite(Limit_45, 0, 0);
    Put_Walls_Sprite(Limit_46, 0, 0);
    Put_Walls_Sprite(Limit_47, 0, 0);
    Put_Walls_Sprite(Limit_48, 0, 0);
    Put_Walls_Sprite(Limit_49, 0, 0);
    Put_Walls_Sprite(Limit_50, 0, 0);
    Put_Walls_Sprite(Limit_51, 0, 0);
    Put_Walls_Sprite(Limit_52, 0, 0);

    //Add Limits to Scene
    Add_Limits_to_Scene();

    //Set Limits
    Set_Walls_Pos(Limit_1, 0, 0);
    Set_Walls_Pos(Limit_2, 1, 0);
    Set_Walls_Pos(Limit_3, 2, 0);
    Set_Walls_Pos(Limit_4, 3, 0);
    Set_Walls_Pos(Limit_5, 4, 0);
    Set_Walls_Pos(Limit_6, 5, 0);
    Set_Walls_Pos(Limit_7, 6, 0);
    Set_Walls_Pos(Limit_8, 7, 0);
    Set_Walls_Pos(Limit_9, 8, 0);
    Set_Walls_Pos(Limit_10, 9, 0);
    Set_Walls_Pos(Limit_11, 10, 0);
    Set_Walls_Pos(Limit_12, 11, 0);
    Set_Walls_Pos(Limit_13, 12, 0);
    Set_Walls_Pos(Limit_14, 13, 0);
    Set_Walls_Pos(Limit_15, 14, 0);
    Set_Walls_Pos(Limit_16, 15, 0);
    Set_Walls_Pos(Limit_17, 0, 11);
    Set_Walls_Pos(Limit_18, 1, 11);
    Set_Walls_Pos(Limit_19, 2, 11);
    Set_Walls_Pos(Limit_20, 3, 11);
    Set_Walls_Pos(Limit_21, 4, 11);
    Set_Walls_Pos(Limit_22, 5, 11);
    Set_Walls_Pos(Limit_23, 6, 11);
    Set_Walls_Pos(Limit_24, 7, 11);
    Set_Walls_Pos(Limit_25, 8, 11);
    Set_Walls_Pos(Limit_26, 9, 11);
    Set_Walls_Pos(Limit_27, 10, 11);
    Set_Walls_Pos(Limit_28, 11, 11);
    Set_Walls_Pos(Limit_29, 12, 11);
    Set_Walls_Pos(Limit_30, 13, 11);
    Set_Walls_Pos(Limit_31, 14, 11);
    Set_Walls_Pos(Limit_32, 15, 11);
    Set_Walls_Pos(Limit_33, 0, 1);
    Set_Walls_Pos(Limit_34, 0, 2);
    Set_Walls_Pos(Limit_35, 0, 3);
    Set_Walls_Pos(Limit_36, 0, 4);
    Set_Walls_Pos(Limit_37, 0, 5);
    Set_Walls_Pos(Limit_38, 0, 6);
    Set_Walls_Pos(Limit_39, 0, 7);
    Set_Walls_Pos(Limit_40, 0, 8);
    Set_Walls_Pos(Limit_41, 0, 9);
    Set_Walls_Pos(Limit_42, 0, 10);
    Set_Walls_Pos(Limit_43, 15, 1);
    Set_Walls_Pos(Limit_44, 15, 2);
    Set_Walls_Pos(Limit_45, 15, 3);
    Set_Walls_Pos(Limit_46, 15, 4);
    Set_Walls_Pos(Limit_47, 15, 5);
    Set_Walls_Pos(Limit_48, 15, 6);
    Set_Walls_Pos(Limit_49, 15, 7);
    Set_Walls_Pos(Limit_50, 15, 8);
    Set_Walls_Pos(Limit_51, 15, 9);
    Set_Walls_Pos(Limit_52, 15, 10);
}

void game::Add_Limits_to_Scene()
{
    addItem(Limit_1);
    addItem(Limit_2);
    addItem(Limit_3);
    addItem(Limit_4);
    addItem(Limit_5);
    addItem(Limit_6);
    addItem(Limit_7);
    addItem(Limit_8);
    addItem(Limit_9);
    addItem(Limit_10);
    addItem(Limit_11);
    addItem(Limit_12);
    addItem(Limit_13);
    addItem(Limit_14);
    addItem(Limit_15);
    addItem(Limit_16);
    addItem(Limit_17);
    addItem(Limit_18);
    addItem(Limit_19);
    addItem(Limit_20);
    addItem(Limit_21);
    addItem(Limit_22);
    addItem(Limit_23);
    addItem(Limit_24);
    addItem(Limit_25);
    addItem(Limit_26);
    addItem(Limit_27);
    addItem(Limit_28);
    addItem(Limit_29);
    addItem(Limit_30);
    addItem(Limit_31);
    addItem(Limit_32);
    addItem(Limit_33);
    addItem(Limit_34);
    addItem(Limit_35);
    addItem(Limit_36);
    addItem(Limit_37);
    addItem(Limit_38);
    addItem(Limit_39);
    addItem(Limit_40);
    addItem(Limit_41);
    addItem(Limit_42);
    addItem(Limit_43);
    addItem(Limit_44);
    addItem(Limit_45);
    addItem(Limit_46);
    addItem(Limit_47);
    addItem(Limit_48);
    addItem(Limit_49);
    addItem(Limit_50);
    addItem(Limit_51);
    addItem(Limit_52);
}

void game::Create_Memory_Limits()
{
    Limit_1 = new Wall(0,0,0);
    Limit_2 = new Wall(0,0,0);
    Limit_3 = new Wall(0,0,0);
    Limit_4 = new Wall(0,0,0);
    Limit_5 = new Wall(0,0,0);
    Limit_6 = new Wall(0,0,0);
    Limit_7 = new Wall(0,0,0);
    Limit_8 = new Wall(0,0,0);
    Limit_9 = new Wall(0,0,0);
    Limit_10 = new Wall(0,0,0);
    Limit_11 = new Wall(0,0,0);
    Limit_12 = new Wall(0,0,0);
    Limit_13 = new Wall(0,0,0);
    Limit_14 = new Wall(0,0,0);
    Limit_15 = new Wall(0,0,0);
    Limit_16 = new Wall(0,0,0);
    Limit_17 = new Wall(0,0,0);
    Limit_18 = new Wall(0,0,0);
    Limit_19 = new Wall(0,0,0);
    Limit_20 = new Wall(0,0,0);
    Limit_21 = new Wall(0,0,0);
    Limit_22 = new Wall(0,0,0);
    Limit_23 = new Wall(0,0,0);
    Limit_24 = new Wall(0,0,0);
    Limit_25 = new Wall(0,0,0);
    Limit_26 = new Wall(0,0,0);
    Limit_27 = new Wall(0,0,0);
    Limit_28 = new Wall(0,0,0);
    Limit_29 = new Wall(0,0,0);
    Limit_30 = new Wall(0,0,0);
    Limit_31 = new Wall(0,0,0);
    Limit_32 = new Wall(0,0,0);
    Limit_33 = new Wall(0,0,0);
    Limit_34 = new Wall(0,0,0);
    Limit_35 = new Wall(0,0,0);
    Limit_36 = new Wall(0,0,0);
    Limit_37 = new Wall(0,0,0);
    Limit_38 = new Wall(0,0,0);
    Limit_39 = new Wall(0,0,0);
    Limit_40 = new Wall(0,0,0);
    Limit_41 = new Wall(0,0,0);
    Limit_42 = new Wall(0,0,0);
    Limit_43 = new Wall(0,0,0);
    Limit_44 = new Wall(0,0,0);
    Limit_45 = new Wall(0,0,0);
    Limit_46 = new Wall(0,0,0);
    Limit_47 = new Wall(0,0,0);
    Limit_48 = new Wall(0,0,0);
    Limit_49 = new Wall(0,0,0);
    Limit_50 = new Wall(0,0,0);
    Limit_50 = new Wall(0,0,0);
    Limit_51 = new Wall(0,0,0);
    Limit_52 = new Wall(0,0,0);
}

void game::Delete_Memory_Limits()
{
    delete Limit_1;
    delete Limit_2;
    delete Limit_3;
    delete Limit_4;
    delete Limit_5;
    delete Limit_6;
    delete Limit_7;
    delete Limit_8;
    delete Limit_9;
    delete Limit_10;
    delete Limit_11;
    delete Limit_12;
    delete Limit_13;
    delete Limit_14;
    delete Limit_15;
    delete Limit_16;
    delete Limit_17;
    delete Limit_18;
    delete Limit_19;
    delete Limit_20;
    delete Limit_21;
    delete Limit_22;
    delete Limit_23;
    delete Limit_24;
    delete Limit_25;
    delete Limit_26;
    delete Limit_27;
    delete Limit_28;
    delete Limit_29;
    delete Limit_30;
    delete Limit_31;
    delete Limit_32;
    delete Limit_33;
    delete Limit_34;
    delete Limit_35;
    delete Limit_36;
    delete Limit_37;
    delete Limit_38;
    delete Limit_39;
    delete Limit_40;
    delete Limit_41;
    delete Limit_42;
    delete Limit_43;
    delete Limit_44;
    delete Limit_45;
    delete Limit_46;
    delete Limit_47;
    delete Limit_48;
    delete Limit_49;
    delete Limit_50;
    delete Limit_51;
    delete Limit_52;
}
