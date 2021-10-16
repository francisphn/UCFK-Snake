/**
 * Program: UCFK4 Snake
 * Module: snake.c
 * Authors: Francis Phan, Richard Li
 * Description: A reconstruction of the old fashioned Nokia Snake
 *              game for the UC Fun Kit 4. This module covers the main
 *              functionalities of the game. 
 */


// 1. Modules used in this module --------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "system.h"
#include "navswitch.h"
#include "tinygl.h"
#include "pacer.h"
#include "../fonts/font3x5_1.h"
#include "font.h"

#include "snake.h"
#include "messages.h"


// 2. Intialisation of tinygl ------------------------------------
void tiny_init(void)
{
    tinygl_init(LOOP_RATE); // value found in header file snake.h
    tinygl_font_set (&font3x5_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE); // horizontal
}

// 3. Game initialization module ---------------------------------

void snake_init(void)
{
    system_init(); // Intialise system
    tiny_init(); // Call the tiny_init module above to initialise tinygl
    navswitch_init(); // Call navswitch_init module to initialise navswitch
}


// Main function -------------------------------------------------

int main (void)
{
    snake_init(); // Call the game initialisation module
    welcome_msg(); // Run the welcome msg module found in messages.c
    lose_msg();
    return 0;
}
