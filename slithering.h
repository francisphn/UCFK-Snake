/**
 * Program: UCFK4 Snake
 * Module: Header file for slithering.c
 * Authors: Francis Phan, Richard Li
 */


#ifndef SLITHERING_H
#define SLITHERING_H

// Include necessary header files

#include <stdlib.h>
#include "system.h"
#include "tinygl.h"


// Define constans used in slithering.c
#define START_SNAKE_MODE 0
#define APPLE_MODE 1
#define PACER_RATE 500
#define LOOP_RATE 300
#define SNAKE_SPEED 1
#define MESSAGE_RATE 20
#define BUTTON_RATE 300
#define LED_ON 1
#define LED_OFF 0


/* Define the snake location and direction */
#define SNAKE_START_X_POS 1
#define SNAKE_START_Y_POS 1
#define SNAKE_START_DIRECTION NORTH


/* This is the snake struct */
enum dir {DIR_N, DIR_E, DIR_S, DIR_W};

typedef enum dir dir_t;

struct snake
{
    
    tinygl_point_t pos; /* Current head of snake.  */
    enum dir dir; /* Current direction.  */
    uint16_t length; // Current length of the snake
    tinygl_point_t tail; // Current tail of the snake
};

typedef struct snake snake_t;

#endif
