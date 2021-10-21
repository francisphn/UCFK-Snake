/**
 * Program: UCFK4 Snake
 * Module: game.c
 * Authors: Francis Phan, Richard Li
 * Description: The main function.
**/


/** INCLUDE HEADER FILES  **/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

#include "slithering.h"
#include "game.h"
#include "messages.h"


/** A function to generate a random integer.
 * @param upper bound, lower bound
 * @return an integer within the bound inclusive **/

int randomiser(int upper, int lower)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}


/** This function is called to restart the game, and to display the message SNAKE **/

int coord(void)
{
    system_init();
    navswitch_init();
    tinygl_init(LOOP_RATE);
    tinygl_font_set (&font3x5_1);
    pacer_init(PACER_RATE);

    int outcome = display_text(SNAKE_TEXT, PUSH_NAVSWITCH_TO_EXIT);
    int restart_check = 0;
    if (outcome == 1) {
        tinygl_clear();
        int level = level_chooser();
        restart_check = control(level);
        if (restart_check == RESTART) {
            return RESTART;
        }
    }
    return 0;
}


/** Main Function **/

int main(void) 
{
    navswitch_init();
    int restart_check = 0;
    while (true) {
        restart_check = coord();
        if (restart_check == RESTART) {
            continue;
        }
    }
}
