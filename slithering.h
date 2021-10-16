/**  @file   slithering.h
     @author Liyinqin Li
     @date   16/10/21

*/

#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>
#include "system.h"
#include "tinygl.h"
#include "ir_uart.h"

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
