
#ifndef GLOBAL_MACROS_H
#define GLOBAL_MACROS_H

#include "macros_vitales.h"

//General
#define Scale 3
#define Check 1

//Main Character (mc)
    //Movement
#define Walk_Speed_mc 5

    //Animation
#define _Walk_Animation_Speed_mc 500
#define Dead_Animation_Speed_mc 150

    //Medidas
#define pos_x_initial_mc (wall_ancho * Scale)
#define pos_y_initial_mc (wall_alto * Scale)


//Wall
    //Animation
#define wall_Destruction_Speed 100


//Bomb
    //Animation
        //Bomb
#define bomb_charge_animation_repeat (4 * bomb_charge_frame_ammount)
#define bomb_Animation_Speed 200
        //Explosion
#define explosion_Animation_Speed 50


//Enemy
    //Position
#define enemy_posx_block_initial 8
#define enemy_posy_block_initial 1
#define enemy_Speed 10
    //Animation
#define enemy_Walk_Animation_Speed 200
#define enemy_Dead_Animation_Speed 300
#define enemy_change_direction 5000
    //Other
#define enemy_Quantity 8

#endif // GLOBAL_MACROS_H
