/**
 * Program: UCFK4 Snake
 * Module: game.c
 * Authors: Francis Phan, Richard Li
 * Description: A reconstruction of the old fashioned Nokia Snake
 *              game for the UC Fun Kit 4. This module covers the main
 *              functionalities of the game. 
 */


// 1. Modules used in this module --------------------------------
#include "system.h"
#include "navswitch.h"
#include "tinygl.h"
#include "pacer.h"
#include "../fonts/font3x5_1.h"

#include "snake.h"


// 2. Intialisation of tinygl ------------------------------------
void tiny_init(void) 
{
    // Refer to the definitions of PACER_RATE, MESSAGE_RATE etc. in game.h
    tinygl_init (PACER_RATE); 
    tinygl_font_set (&font3x5_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
}

// 3. Setting game initial state ---------------------------------
void game_init(void)
{
    continue;
}

// 4, Initialisation of
