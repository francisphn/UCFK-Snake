/**
 * Program: UCFK4 Snake
 * Module: Header file for messages.c
 * Authors: Francis Phan, Richard Li
**/


#ifndef MESSAGES_H
#define MESSAGES_H

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


/* Tinygl self-defined functions */

/** Initialise tinygl.
 * @param none
 * @return 0 **/
int tiny_text_init(void);

/** Display text, be it Well played, Game Over, or Snake
 * @param text code (0 for Snake, 1 for Game Over, 2 for Well Played) and if closing the message by pushing the navswitch button is needed
 * @return 1 if the navswitch has been pressed, if navswitch is needed to close the message, else return 0 **/
int display_text(int text_to_display, int require_exit_by_pushing_navswitch);

/** Allows user to choose Level 1 2 or 3 using the navswitch
 * @param none.
 * @return the chosen level **/
int level_chooser(void);

/** Display user score 
 * @param the snake
 * @return 1 if the navswitch is pushed to exit the user score screen **/
int display_score(snake_t my_snake);

#endif