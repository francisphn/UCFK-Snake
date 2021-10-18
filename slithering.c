/**
 * Program: UCFK4 Snake
 * Module: slithering.c
 * Authors: Francis Phan, Richard Li
 * Description: This module provides for some modules
 *              to be simulate a snake on the LED matrix.
 **/








// Include header files
#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "navswitch.h"
#include "slithering.h"





/** snake_move 
This function is called to increment or decrement the X or Y position of
the snake head when it is called by another function. The purpose is to move
the snake forward, that is, if it is called and the current direction of the
snake is South, then the snake will move south. 
    @param is to accept the snake struct itself. 
    @effects tinygl will then draw this position 
    @return it will return the updated snake struct, where by 
            the direction of the snake struct has been moved by 1 step forward 
**/

static snake_t snake_move (snake_t snake)
{
    switch (snake.dir)
    {
        case DIR_N:
            snake.pos.y--;
            break;

        case DIR_E:
            snake.pos.x++;
            break;

        case DIR_S:
            snake.pos.y++;
            break;

        case DIR_W:
            snake.pos.x--;
            break;
    }

    tinygl_draw_point (snake.pos, 1);
    return snake;

}





/** snake_move 
This function is called to increment or decrement the X or Y position of
the snake head when it is called by another function. The purpose is to move
the snake forward, that is, if it is called and the current direction of the
snake is South, then the snake will move south. 
    @param is to accept the snake struct itself. 
    @effects tinygl will then draw this position 
    @return it will return the updated snake struct, where by 
            the direction of the snake struct has been moved by 1 step forward 
**/

/** snake turn 
These functions are called to turn the snake when controlled by the navswitch.
    @param is to accept the snake struct itself. 
    @return the snake struct that has been updated.
 **/

static snake_t snake_turn_left (snake_t snake)
{
    dir_t newdir[] = {DIR_W, DIR_N, DIR_E, DIR_S};

    snake.dir = newdir[snake.dir];
    return snake;
}

static snake_t snake_turn_right (snake_t snake)
{
    dir_t newdir[] = {DIR_E, DIR_S, DIR_W, DIR_N};

    snake.dir = newdir[snake.dir];
    return snake;
}

static snake_t snake_turn_up (snake_t snake)
{
    dir_t newdir[] = {DIR_N, DIR_E, DIR_S, DIR_W};

    snake.dir = newdir[snake.dir];
    return snake;
}

static snake_t snake_turn_down (snake_t snake)
{
    dir_t newdir[] = {DIR_S, DIR_W, DIR_N, DIR_E};

    snake.dir = newdir[snake.dir];
    return snake;
}

int control (void)
{
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

