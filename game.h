/**
 * Program: UCFK4 Snake
 * Module: Header file for game.c
 * Authors: Francis Phan, Richard Li
**/


#ifndef GAME_H
#define GAME_H


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

/** A function to generate a random integer.
 * @param upper bound, lower bound
 * @return an integer within the bound inclusive **/
int randomiser(int upper, int lower);

/** This function is called to restart the game, and to display the message SNAKE **/
int coord(void);

#endif
