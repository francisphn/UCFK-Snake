/**
 * Program: UCFK4 Snake
 * Module: Header file for slithering.c
 * Authors: Francis Phan, Richard Li
**/


#ifndef SLITHERING_H
#define SLITHERING_H


/** INCLUDE HEADER FILES  **/

#include <stdint.h>
#include <stdlib.h>

#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "navswitch.h"
#include "led.h"
#include "display.h"
#include "../fonts/font3x5_1.h"
#include "font.h"



/** CONSTANTS USED IN SLITHERING.C **/

#define START_SNAKE_MODE 0
#define APPLE_MODE 1
#define PACER_RATE 500
#define LOOP_RATE 300
#define SNAKE_SPEED 1.5
#define MESSAGE_RATE 20
#define BUTTON_RATE 300
#define LED_ON 1
#define LED_OFF 0


/* Define the snake location and direction */
#define SNAKE_START_X_POS 1
#define SNAKE_START_Y_POS 1
#define SNAKE_START_DIRECTION NORTH

/* strings to display on the LED matrix */
#define SNAKE_TEXT 0
#define GAME_OVER_TEXT 1
#define WELL_PLAYED_TEXT 2

/* Game Level */
#define GAME_EASY 0
#define GAME_MEDIUM 1  
#define GAME_ADVANCED 2  

/* Navswitch scanner as strings are displayed */
#define PUSH_NAVSWITCH_TO_EXIT 1
#define NO_EXIT 0

#define NAVSWITCH_PUSH_IDENTIFIER_SCAN_PUSH_DOWN_ONLY 0
#define NAVSWITCH_PUSH_IDENTIFIER_SCAN_ALL 1

#define NAVSWITCH_PUSHED_DOWN 0
#define NAVSWITCH_PUSHED_NORTH 1
#define NAVSWITCH_PUSHED_SOUTH 2
#define NAVSWITCH_PUSHED_WEST 3
#define NAVSWITCH_PUSHED_EAST 4

#define GAME_FIRST_START 1
#define GAME_ALREADY_STARTED 0

#define SNAKE_MAX_LENGTH = 11;

/** Direction struct **/
enum direction {NORTH, EAST, SOUTH, WEST};
typedef enum direction direction_t;

/* This is the snake struct */
struct snake
{
    tinygl_point_t head; /* Current head of snake.  */
    direction_t head_direction; /* Current direction.  */

    tinygl_point_t body[10]; // Current body of snake
    direction_t body_direction[10]; 
    uint16_t length; // Current length of the snake
};
typedef struct snake snake_t;


/* struct of an apple */
struct apple
{
    tinygl_point_t location; // X and Y location of the apple
};
typedef struct apple apple_t;

#endif
