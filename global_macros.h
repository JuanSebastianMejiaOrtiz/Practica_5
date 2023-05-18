
#ifndef GLOBAL_MACROS_H
#define GLOBAL_MACROS_H

//General
#define Scale 2

//Main Character (mc)
    //Movement
#define Walk_Speed_mc 3

    //Animation
#define _Walk_Animation_Speed_mc 200
#define Walk_Animation_Frame_Ammount_mc 3
#define Dead_Animation_Speed_mc 200
#define Dead_Animation_Frame_Ammount_mc 7

    //Medidas
#define alto_mainchar 16
#define ancho_mainchar 16
#define pos_x_initial_mc 32
#define pos_y_initial_mc 32
#define number_lines_mc 3
#define number_cols_mc 7


//Wall
    //Animation
#define wall_Destruction_Frame_Ammount 7
#define walls_extra 2
#define wall_Destruction_Speed 200

    //Medidas
#define wall_alto 16
#define wall_ancho 16


//Bomb
    //Animation
#define bomb_charge_frame_ammount 3

    //Medidas
#define bomb_ancho 16
#define bomb_alto 16


//Map
#define Limits_Wall_Quantity_x 100
#define Limits_Wall_Quantity_y 38

#endif // GLOBAL_MACROS_H
