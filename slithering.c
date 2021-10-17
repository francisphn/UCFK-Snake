/*
 * snake.c
 *
 * Copyright 2021 Yinqin Li <yli356@cs19100bs>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "navswitch.h"

#define LOOP_RATE 300
#define SNAKE_SPEED 1

enum dir {DIR_N, DIR_E, DIR_S, DIR_W};

typedef enum dir dir_t;

struct snake
{
    /* Current head of snake.  */
    tinygl_point_t pos;
    /* Current direction.  */
    enum dir dir;
};

typedef struct snake snake_t;

static snake_t snake_move (snake_t snake)
{
    switch (snake.dir)
    {
        case DIR_N:
            snake.pos.y = snake.pos.y - 1;
            break;

        case DIR_E:
            snake.pos.x = snake.pos.x + 1;
            break;

        case DIR_S:
            snake.pos.y = snake.pos.y + 1;
            break;

        case DIR_W:
            snake.pos.x = snake.pos.x - 1;
            break;
    }
    tinygl_draw_point (snake.pos, 1);
    return snake;
}

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

int main (void)
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

