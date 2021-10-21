/**
 * Program: UCFK4 Snake
 * Module: Header file for slithering.c
 * Authors: Francis Phan, Richard Li
**/


#ifndef SLITHERING_H
#define SLITHERING_H


/** HEADER FILES  **/

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
#include "pio.h"
#include "button.h"
/** CONSTANTS USED IN SLITHERING.C ------------------------------------------------------------------ **/

/* Basic constants */
#define START_SNAKE_MODE 0
#define APPLE_MODE 1
#define PACER_RATE 500
#define LOOP_RATE 300
#define MESSAGE_RATE 20
#define BUTTON_RATE 300
#define LED_ON 1
#define LED_OFF 0

/* strings to display on the LED matrix */
#define SNAKE_TEXT 0
#define GAME_OVER_TEXT 1
#define WELL_PLAYED_TEXT 2

/* Navswitch scanner as strings are displayed */
#define PUSH_NAVSWITCH_TO_EXIT 1
#define NO_EXIT 0

/* Navswtich directions */
#define NAVSWITCH_PUSHED_DOWN 0
#define NAVSWITCH_PUSHED_NORTH 1
#define NAVSWITCH_PUSHED_SOUTH 2
#define NAVSWITCH_PUSHED_WEST 3
#define NAVSWITCH_PUSHED_EAST 4

#define GAME_FIRST_START 1
#define GAME_ALREADY_STARTED 0

#define SNAKE_MAX_LENGTH = 11;

/* Restart game code */
#define RESTART 5

/* Connect piezo tweeter to pins 6 and 8 of UCFK4 P1 connector
   for push-pull operation.  */
#define PIEZO_PIO PIO_DEFINE (PORT_D, 6)
#define PIEZO1_PIO PIO_DEFINE (PORT_D, 4)
#define PIEZO2_PIO PIO_DEFINE (PORT_D, 6)

/** STRUCT -------------------------------------------------------------------------------------- **/

/* Direction struct */
enum direction {NORTH, EAST, SOUTH, WEST};
typedef enum direction direction_t;

/* Snake struct */
struct snake
{
    tinygl_point_t head; /* Current head of snake.  */
    direction_t head_direction; /* Current direction.  */

    tinygl_point_t body[12]; // Current body of snake
    direction_t body_direction[12];
    uint16_t body_length; // Current length of the snake
};
typedef struct snake snake_t;

/* Apple struct */
struct apple
{
    tinygl_point_t location; // X and Y location of the apple
};
typedef struct apple apple_t;


/** SIGNATURES -------------------------------------------------------------------------------------- **/

/** Automatically slither the snake
 * @param the snake itself
 * @return the snake itself **/
snake_t snake_slither_forward(snake_t snake);

/** This function will check if the snake has crossed the matrix's boundary. 
 * @param the snake itself. 
 * @return the RESTART code if game is over **/
int check_boundary_cross(snake_t snake);

/** Check if the snake has collided with itself 
 * @param the snake itself. 
 * @return the RESTART code if game is over **/
int check_collision(snake_t snake);

/** Grow the snake 
 * @param the snake itself. 
 * @return the snake that has been grown **/
snake_t snake_grow(snake_t my_snake);

/** Grow the snake 
 * @param the snake itself. 
 * @return the snake that has been grown **/
snake_t snake_init(void);

/** A function to randomise a number between two bounds inclusive
 * @param upper bound, lower bound 
 * @return a random integer in that bound inclusive **/
int randomiser(int upper, int lower);

/** Make a new apple at a location that isn't where the snake is 
 * @param the snake including its location
 * @return an apple **/
apple_t make_apple(snake_t snake);

/** Main function to coordinate the game **/
int control(int level);

#endif
