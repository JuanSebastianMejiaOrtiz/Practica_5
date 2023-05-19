
#ifndef GLOBAL_MACROS_H
#define GLOBAL_MACROS_H

//General
#define Scale 3

//Main Character (mc)
    //Movement
#define Walk_Speed_mc 4

    //Animation
#define _Walk_Animation_Speed_mc 200
#define Walk_Animation_Frame_Ammount_mc 3
#define Dead_Animation_Speed_mc 200
#define Dead_Animation_Frame_Ammount_mc 7

    //Medidas
#define alto_mainchar 16
#define ancho_mainchar 16
#define pos_x_initial_mc (wall_ancho*Scale)
#define pos_y_initial_mc (wall_alto*Scale)
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
        //Bomb
#define bomb_charge_frame_ammount 3
#define bomb_charge_animation_repeat 3
#define bomb_Animation_Speed 400
#define bomb_Cooldown (bomb_Animation_Speed * bomb_charge_frame_ammount * bomb_charge_animation_repeat)
        //Explosion
#define explosion_Animation_Speed 200
#define explosion_frame_ammount 4
#define explosion_alto_frame_ammount 5
#define explosion_ancho_frame_ammount 5

    //Medidas
#define bomb_ancho 16
#define bomb_alto 16
#define explosion_ancho_box 16
#define explosion_alto_box 16


//Map
#define Limits_Wall_One_Side_Quantity_x 16
#define Limits_Wall_One_Side_Quantity_y 12

#endif // GLOBAL_MACROS_H
