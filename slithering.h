/**
 * Program: UCFK4 Snake
 * Module: Header file game.h for snake control module slitering.h
 * Authors: Francis Phan, Richard Li
 */

#ifndef SLITHERING_H
#define SLITHERING_H

#include <stdlib.h>
#include "system.h"
#include "tinygl.h"

#define START_SNAKE_MODE 0
#define APPLE_MODE 1
#define PACER_RATE 500
#define LOOP_RATE 500
#define MESSAGE_RATE 20
#define BUTTON_RATE 300
#define LED_ON 1
#define LED_OFF 0

/* Define the snake location and direction */
#define SNAKE_START_X_POS 1
#define SNAKE_START_Y_POS 1
#define SNAKE_START_DIRECTION NORTH

/* This is the snake struct */
typedef struct snake_part_s SnakePart;

struct snake_part_s
{
    int8_t x.pos;
    int8_t y.pos;
    SnakePart* next;
}

#endif
