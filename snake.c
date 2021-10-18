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
#include "slithering.h"


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

int main(void)
{
    snake_init(); // Call the game initialisation module
    welcome_msg(); // Run the welcome msg module found in messages.c

    snake_t snake;
    int tick = 0;

    system_init ();

    snake.dir = DIR_N;
    snake.pos.x = 0;
    snake.pos.y = TINYGL_HEIGHT - 1;

    tinygl_init (LOOP_RATE);
    navswitch_init();
    pacer_init (LOOP_RATE);
    tinygl_draw_point (snake.pos, 1);

    while (1)
    {
        pacer_wait ();
        //tinygl_clear ();
        navswitch_update ();
        tick = tick + 1;
        if (tick > LOOP_RATE / SNAKE_SPEED)
        {
            tick = 0;
            snake = snake_move (snake);
        }
        if (navswitch_push_event_p (NAVSWITCH_EAST)) {
            snake = snake_turn_right (snake);
        } else if (navswitch_push_event_p (NAVSWITCH_WEST)) {
            snake = snake_turn_left (snake);
        } else if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
            snake = snake_turn_up (snake);
        } else if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
            snake = snake_turn_down (snake);
        }
        tinygl_update ();
    }
    return 0;
}
