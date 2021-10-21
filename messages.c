/**
 * Program: UCFK4 Snake
 * Module: messages.c
 * Authors: Francis Phan, Richard Li
 * Description: Tinygl modules to display various menus and texts in the
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


/** Initialise tinygl.
 * @param none
 * @return 0 **/

int tiny_text_init(void) 
{
    tinygl_init(LOOP_RATE);
    tinygl_font_set(&font3x5_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set(TINYGL_TEXT_DIR_ROTATE); // horizontal
    return 0;
}


/** Display text, be it Well played, Game Over, or Snake
 * @param text code (0 for Snake, 1 for Game Over, 2 for Well Played) and if closing the message by pushing the navswitch button is needed
 * @return 1 if the navswitch has been pressed, if navswitch is needed to close the message, else return 0 **/

int display_text(int text_to_display, int require_exit_by_pushing_navswitch)
{
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_clear();
    tiny_text_init();

    if (text_to_display == 0) {
        tinygl_text("SNAKE SNAKE SNAKE SNAKE SNAKE SNAKE SNAKE");
    } else if (text_to_display == 1) {
        tinygl_text("GAME OVER GAME OVER GAME OVER GAME OVER GAME OVER");
    } else if (text_to_display == 2) {
        tinygl_text("WELL PLAYED WELL PLAYED WELL PLAYED WELL PLAYED WELL PLAYED");
    }
    navswitch_init();
    pacer_init (LOOP_RATE);

    while (1)
    {
        pacer_wait(); /* Wait for next tick.  */
        tinygl_update();
        navswitch_update();

        if (require_exit_by_pushing_navswitch == PUSH_NAVSWITCH_TO_EXIT) {
            if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
                return 1;
            } 
        }

    }
    return 0;
}


/** Allows user to choose Level 1 2 or 3 using the navswitch
 * @param none.
 * @return the chosen level **/

int level_chooser(void)
{
    int level = 1;

    tinygl_clear();
    tiny_text_init();
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);
    tinygl_text("L1");

    while(1)
    {
        pacer_wait();
        tinygl_update();
        navswitch_update();

        if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
            if (level == 3) {
                level = 1;
            } else {
                level++;
            }
        
            if (level == 1) {
                tinygl_text("L1");
            } else if (level == 2) {
                tinygl_text("L2");
            } else if (level == 3) {
                tinygl_text("L3");
            }

        } else if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {

            if (level == 1) {
                level = 3;
            } else {
                level--;
            }
        
            if (level == 1) {
                tinygl_text("L1");
            } else if (level == 2) {
                tinygl_text("L2");
            } else if (level == 3) {
                tinygl_text("L3");
            }
        } else if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            tinygl_clear();
            return level;
        }
    }
    return 0;
}


/** Display user score 
 * @param the snake
 * @return 1 if the navswitch is pushed to exit the user score screen **/

int display_score(snake_t my_snake)
{
    tiny_text_init();
    tinygl_text_mode_set(TINYGL_TEXT_MODE_STEP);
    tinygl_clear(); // clear
    switch(my_snake.body_length) {
        case 0:
            tinygl_text("00");
            break;
        case 1:
            tinygl_text("01");
            break;
        case 2:  
            tinygl_text("02");
            break;
        case 3:  
            tinygl_text("03");
            break;
        case 4:  
            tinygl_text("04");
            break;
        case 5:  
            tinygl_text("05");
            break;
        case 6:  
            tinygl_text("06");
            break;
        case 7:  
            tinygl_text("07");
            break;
        case 8:  
            tinygl_text("08");
            break;
        case 9:  
            tinygl_text("09");
            break;
        case 10:  
            tinygl_text("10");
            break;
        case 11:
            tinygl_text("11");
            break;
        case 12:
            tinygl_text("12");
            break;
    }


    navswitch_init();
    pacer_init (LOOP_RATE);

    while (1)
    {
        pacer_wait(); /* Wait for next tick.  */
        tinygl_update();
        navswitch_update();

        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            return 1;
        } 

    }
    return 0;
}