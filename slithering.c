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


#include <stdio.h>
#include <stdlib.h>
#include "tinygl.h"
#include "system.h"

#include "snake.h"

/* make a new snake to begin the game. */
void snake_make (Snake* snake)
{
    Snake* new_head = malloc(sizeof(Snake));
    Snake* new_tail = malloc(sizeof(Snake));

    new_head->x.pos = SNAKE_START_X_POS;
    new_head->y.pos = SNAKE_START_Y_POS;
    new_head->next = new_tail;

    new_tail->x.pos = SNAKE_START_X_POS;
    new_tail->y.pos = SNAKE_START_Y_POS;
    new_tail->next = NULL;

    snake->head = new_head;
    snake->num_food_eating = 0;
    snake->score = 0;
    snake->direction = SNAKE_START_DIRECTION;
}

/* make a new snake to restart the game. */
void snake_reset (Snake* snake)
{
    Snake* current = snake->head;
    Snake* prev = current;
    while (current) {
        prev = current;
        current = current->next;
        free(prev);
    }
    snake_make (snake);
}

/* set the snake's direction to be the given direction. */
void snake_direction (Snake* snake, int8_t direction)
{
    snake->direction = direction;
}

void snake_move (Snake* snake)
{
    switch
    {
        case NORTH:
            snake.y.pos = snake.y.pos - 1;
            break;

        case EAST:
            snake.x.pos = snake.x.pos + 1;
            break;

        case SOUTH:
            snake.y.pos = snake.y.pos + 1;
            break;

        case WEST:
            snake.x.pos = snake.x.pos - 1;
            break;
    }
}
