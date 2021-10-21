/**
 * Program: UCFK4 Snake
 * Module: game.c
 * Authors: Francis Phan, Richard Li
 * Description: This module provides for some modules
 *              to be simulate a snake on the LED matrix.
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
