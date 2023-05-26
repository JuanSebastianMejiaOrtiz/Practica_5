
#ifndef GLOBAL_MACROS_H
#define GLOBAL_MACROS_H

//General
#define Scale 3
#define Check 1
#define Total_Number_of_Walls (Number_of_Limits + Number_of_Inside_Walls)

//Main Character (mc)
    //Movement
#define Walk_Speed_mc 4

    //Animation
#define _Walk_Animation_Speed_mc 500
#define Walk_Animation_Frame_Ammount_mc 3
#define Dead_Animation_Speed_mc 150
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

    //Ammount
#define Number_Limits_x_One_side 16
#define Number_Limits_y_One_side 10
#define Number_of_Limits ((Number_Limits_x_One_side * 2) + (Number_Limits_y_One_side * 2))
#define Number_of_Inside_Walls 40


//Bomb
    //Animation
        //Bomb
#define bomb_charge_frame_ammount 3
#define bomb_charge_animation_repeat (3 * bomb_charge_frame_ammount)
#define bomb_Animation_Speed 200
        //Explosion
#define explosion_frame_ammount 4
#define explosion_ammount_per_line 2
#define explosion_alto_frame_ammount 5
#define explosion_ancho_frame_ammount 5
#define explosion_Animation_Speed 100

    //Medidas
#define bomb_ancho 16
#define bomb_alto 16
#define explosion_ancho_box 16
#define explosion_alto_box 16

    //Other
#define explosion_size_grid 5


//Enemy
    //Position
#define enemy_posx_block_initial 8
#define enemy_posy_block_initial 1
#define enemy_pos_x_initial (wall_ancho * Scale * enemy_posx_block_initial)
#define enemy_pos_y_initial (wall_alto * Scale * enemy_posy_block_initial)
#define enemy_Speed 10
    //Animation
#define enemy_Walk_Animation_Speed 200
#define enemy_Walk_Animation_Frame_Ammount 3
#define enemy_Dead_Animation_Speed 300
#define enemy_Dead_Animation_Frame_Ammount 5
#define enemy_change_direction 5000
    //Medidas
#define enemy_ancho 16
#define enemy_alto 16
    //Other
#define enemy_Quantity 8


//PowerUps
#define PowerUp_alto 16
#define PowerUp_ancho 16

#endif // GLOBAL_MACROS_H
