/**
 * Program: UCFK4 Snake
 * Module: messages.c
 * Authors: Francis Phan, Richard Li
 * Description: This module provides for some modules
 *              to be used by the main function to display
 *              messages.
 */


// 1. Modules used in this module --------------------------------
#include "system.h"
#include "navswitch.h"
#include "tinygl.h"
#include "pacer.h"
#include "../fonts/font3x5_1.h"
#include "font.h"

#include "messages.h"

// 2. The paced loop
int msg_paced_loop(void)
{
    pacer_init (LOOP_RATE);
    while (1)
    {
        /* Wait for next tick.  */
        pacer_wait ();

        tinygl_update ();

        navswitch_update ();

        if (navswitch_push_event_p (NAVSWITCH_WEST))
            tinygl_text_mode_set (TINYGL_TEXT_MODE_STEP);

        if (navswitch_push_event_p (NAVSWITCH_EAST))
            tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);

    }

    return 0;
}

// 2. Display message to start the game.
int welcome_msg(void)
{
    tinygl_text(MENU_MSG);
    msg_paced_loop();
    return 0;
}

// 3. Display this message when player loses the game
int lose_msg(void)
{
    tinygl_text(LOSE_MSG);
    msg_paced_loop();
    return 0;
}

// 4. Display this message when player wins the game
int win_msg(void)
{
    tinygl_text(WIN_MSG);
    msg_paced_loop();
    return 0;
}
