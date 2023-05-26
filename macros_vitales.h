
#ifndef MACROS_VITALES_H
#define MACROS_VITALES_H

//  WARNING    Esto puede cambiar el funcionamiento base del juego

//General
#define Scale_Characters (Scale-0.2)

//Main character
    //Medidas
#define alto_mainchar 16
#define ancho_mainchar 16
    //Animation
#define Walk_Animation_Frame_Ammount_mc 3
#define Dead_Animation_Frame_Ammount_mc 7
#define number_lines_mc 3
#define number_cols_mc 7


//Wall
    //Animation
#define wall_Destruction_Frame_Ammount 7
#define walls_extra 2
    //Medidas
#define wall_alto 16
#define wall_ancho 16
    //Ammount
#define Number_Limits_x_One_side 16
#define Number_Limits_y_One_side 10
#define Number_of_Limits ((Number_Limits_x_One_side * 2) + (Number_Limits_y_One_side * 2))
#define Number_of_Inside_Walls 40
#define Total_Number_of_Walls (Number_of_Limits + Number_of_Inside_Walls)


//Bomb and explosion

//Bomb
    //Animation
#define bomb_charge_frame_ammount 3

//Explosion
    //Animation
#define explosion_frame_ammount 4
#define explosion_ammount_per_line 2
#define explosion_alto_frame_ammount 5
#define explosion_ancho_frame_ammount 5
    //Medidas
#define bomb_ancho 16
#define bomb_alto 16
#define explosion_ancho_box 16
#define explosion_alto_box 16
#define explosion_size_grid 5


//Enemy
    //Position
#define enemy_pos_x_initial (wall_ancho * Scale * enemy_posx_block_initial)
#define enemy_pos_y_initial (wall_alto * Scale * enemy_posy_block_initial)
    //Animation
#define enemy_Walk_Animation_Frame_Ammount 3
#define enemy_Dead_Animation_Frame_Ammount 5
    //Medidas
#define enemy_ancho 16
#define enemy_alto 16


//PowerUps
    //Medidas
#define PowerUp_alto 16
#define PowerUp_ancho 16

#endif // MACROS_VITALES_H
