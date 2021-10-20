/**
 * Program: UCFK4 Snake
 * Module: slithering.c
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
//#include "piezo.h"
//#include "mmelody.h"

#include "slithering.h"

/** This section will include self-defined tinygl functions **/

/** Initialise tinygl **/

int tiny_text_init(void) 
{
    tinygl_init(LOOP_RATE);
    tinygl_font_set(&font3x5_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set(TINYGL_TEXT_DIR_ROTATE); // horizontal
    return 0;
}


/** display text, either GAME OVER or SNAKE
 * @param the text to display (0 for Snake and 1 for Game over) 
 *            and whether navswitch confirmation is needed  **/

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

/** TODO: DISPLAY SCORE AFTER PRESS
int display_score(int my_score) 
{

}**/

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


/** A function to generate a random integer.
 * @param upper bound, lower bound
 * @return an integer within the bound inclusive **/

int randomiser(int upper, int lower)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

/** A function to increment the length of the snake when it eats an apple.
 * @param the snake itself
 * @return the snake itself **/


/** Automatically slither the snake
 * @param the snake itself
 * @return the snake itself, with the head of the snake incremented
 *          and the tail of the snake decremented to simulate slithering **/

/** TODO: NAVSWITCH TO CONTROL SNAKE**/

snake_t snake_slither_forward(snake_t snake)
{
    /** MOVE THE HEAD **/ 

    //snake = snake_turn(snake);
    snake_t previous_snake = snake;

    tinygl_draw_point(snake.head, 0);

    switch (snake.head_direction) {
        case NORTH:
            snake.head.y--;
            break;
        case EAST:
            snake.head.x++;
            break;
        case SOUTH:
            snake.head.y++;
            break;
        case WEST:
            snake.head.x--;
            break;
    }
    
    for (int index = 0; index < 1; index++) {
        tinygl_draw_point(snake.body[index], 0);
        if (snake.body[index].x != 8 && snake.body[index].y != 8) {
            snake.body_direction[index] = snake.head_direction;
            snake.body[index] = previous_snake.head;
            tinygl_draw_point(snake.body[index], 1);
        }
    }


    tinygl_draw_point(snake.head, 1);

    return snake;
}

/** TODO: move the whole snake **/


/** This function will check if the snake has crossed the matrix's boundary. 
 * @param the snake itself. When cross has been detected, call the display_text function
 * to display game over. **/

int check_boundary_cross(snake_t snake)
{
    if (snake.head.x < 0 || snake.head.x > 4 || snake.head.y < 0 || snake.head.y > 6) {
        int has_exited = display_text(GAME_OVER_TEXT, PUSH_NAVSWITCH_TO_EXIT);
        if (has_exited == 1) {
            return RESTART;
        }
    }
    return 0;
}

/** Check if the snake has collided with itself **/

int check_collision(snake_t snake)
{
    for (int i = 0; i < 10; i++) {
        if (snake.head.x == snake.body[i].x && snake.head.y == snake.body[i].y) {
            int has_exited = display_text(GAME_OVER_TEXT, PUSH_NAVSWITCH_TO_EXIT);
            if (has_exited == 1) {
                return RESTART;
            }
        }
    }
    return 0;
}



snake_t snake_init(void)
{
    /** A snake has 11 parts: 1 part is called the 'head', remaining 10 parts are the 'body' 
     * The snake, when the game first start will have a head.
     * The snake has to eat one apple to grow by one part of the body.
     * We will have to initialise all these 11 parts but we only show the part slithering
     * if the snake has so eaten the apple **/

    snake_t my_snake;

    /** Initialise the head of the snake **/
    my_snake.head.x = randomiser(3, 1);
    my_snake.head.y = randomiser(5, 1);
    my_snake.head_direction = NORTH;

    /** Loop to initialise each part **/
    /** Initialisation of the location of this part will take place by using a fake location 
     * This fake location should be 8, 8 **/

    for (int index = 0; index < 10; index++) {
        my_snake.body[index].x = 8;
        my_snake.body[index].y = 8;
        my_snake.body_direction[index] = NORTH;
    }
    
    my_snake.body_length = 0; // Including the head of the snake

    return my_snake;
}


/** Make an apple with a random location on the matrix. This location shouldn't be where the snake
 * is at the moment, nor will it be at the previous location of the previous apple 
 * @return an apple defined by the apple_t struct **/

apple_t make_apple(snake_t snake)
{
    apple_t my_apple;
    int is_valid_position = 0;
    while (is_valid_position == 0) {
        my_apple.location.x = rand() % 5;
        my_apple.location.y = rand() % 7;

        for (int index = 0; index < 10; index++) { /** LOOP THROUGH THE WHOLE BODY UNTIL VALID LOCATION FOUND **/
            if (my_apple.location.x == snake.body[index].x && my_apple.location.y == snake.body[index].y) {
                continue;
            } else {
                if (my_apple.location.x != snake.head.x && my_apple.location.y != snake.head.y) {
                    is_valid_position = 1; 
                }
            }
        }
    }

    tinygl_draw_point(my_apple.location, 1);
    
    return my_apple;
}

snake_t snake_grow(snake_t my_snake)
{
    /** When the snake first eats an apple, body_length is 1 **/
    if (my_snake.body_length == 1) {
        my_snake.body_direction[0] = my_snake.head_direction;
        if (my_snake.head_direction == NORTH) {
            my_snake.body[0].x = my_snake.head.x;
            my_snake.body[0].y = my_snake.head.y + 1;
        } else if (my_snake.head_direction == SOUTH) {
            my_snake.body[0].x = my_snake.head.x;
            my_snake.body[0].y = my_snake.head.y - 1;
        } else if (my_snake.head_direction == EAST) {
            my_snake.body[0].x = my_snake.head.x - 1;
            my_snake.body[0].y = my_snake.head.y;
        } else if (my_snake.head_direction == WEST) {
            my_snake.body[0].x = my_snake.head.x + 1;
            my_snake.body[0].y = my_snake.head.y;
        }
        tinygl_draw_point(my_snake.body[0], 1);
    } else if (my_snake.body_length > 1) {
        for (int index = 1; index < 10; index++) { /** We want to be using index 0 for the body array **/
            if (my_snake.body[index].x == 8 && my_snake.body[index].y == 8) {
                my_snake.body_direction[index] = my_snake.body_direction[index - 1];
                if (my_snake.body_direction[index - 1] == NORTH) {
                    my_snake.body[index].x = my_snake.body[index - 1].x;
                    my_snake.body[index].y = my_snake.body[index - 1].y + 1;
                } else if (my_snake.body_direction[index - 1] == SOUTH) {
                    my_snake.body[index].x = my_snake.body[index - 1].x;
                    my_snake.body[index].y = my_snake.body[index - 1].y - 1;
                } else if (my_snake.body_direction[index - 1] == EAST) {
                    my_snake.body[index].x = my_snake.body[index - 1].x - 1;
                    my_snake.body[index].y = my_snake.body[index - 1].y;
                } else if (my_snake.body_direction[index - 1] == WEST) {
                    my_snake.body[index].x = my_snake.body[index - 1].x + 1;
                    my_snake.body[index].y = my_snake.body[index - 1].y;
                }
                //tinygl_draw_point(my_snake.body[index], 1);
                break;
            }
        }
    }
    return my_snake;
}

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

/** THE CONTROL FUNCTION **/
int control(int level)
{
    navswitch_init();
    /** Declare and initialise a snake **/
    
    snake_t my_snake;
    my_snake = snake_init();
    int tick = 0;
    float snake_speed = 2;
    float speed_increment = 0.2;
    if (level == 2) {
        speed_increment = 0.3;
    } else if (level == 3) {
        speed_increment = 0.4;
    }
    int restart_check_1 = 0; 
    int restart_check_2 = 0;
    /** A flag to signal that the game has just started **/
    int game_start = GAME_FIRST_START;
    apple_t my_apple;
    int won_user_pressed;
    int menu_score_press;

    while (1) {
        /** Is game over? Check if snake is dead - snake either collided or crossed boundary of matrix **/
        if (game_start == GAME_ALREADY_STARTED) { 
            restart_check_1 = check_boundary_cross(my_snake); /** Check if the snake head has crossed the matrix boundary **/
            restart_check_2 = check_collision(my_snake); /** Check if the snake had has collided with any of its body's 10 parts **/
            if (restart_check_1 == RESTART || restart_check_2 == RESTART) {
                menu_score_press = display_score(my_snake);
                if (menu_score_press == 1) {
                    return RESTART;
                }
            }
        }

        /** Hold the pacer. The pacer_init() is found in the main function 
         * Also do an update on the navswitch continually and update tinygl **/
        pacer_wait(); 
        navswitch_update();
        tinygl_update();

        /** Navswitch turn of the snake **/
        if (navswitch_push_event_p(NAVSWITCH_EAST) == 1) {
            my_snake.head_direction = EAST;
        } else if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
            my_snake.head_direction = SOUTH;
        } else if (navswitch_push_event_p(NAVSWITCH_WEST)) {
            my_snake.head_direction = WEST;
        } else if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
            my_snake.head_direction = NORTH;
        }

        tick++;

        

        if (tick > 300 / snake_speed) {
            tick = 0;
            my_snake = snake_slither_forward(my_snake);
        }

        if (game_start == GAME_FIRST_START) {
                my_apple = make_apple(my_snake);
                game_start = GAME_ALREADY_STARTED;
        } else {
            if (my_snake.head.x == my_apple.location.x && my_snake.head.y == my_apple.location.y) {
                tinygl_draw_point(my_apple.location, 0);
                my_snake.body_length++;
                snake_speed += speed_increment;
                
                
                if (my_snake.body_length == 10) {
                    won_user_pressed = display_text(2, PUSH_NAVSWITCH_TO_EXIT);
                    if (won_user_pressed == 1) {
                        menu_score_press = display_score(my_snake);
                        if (menu_score_press == 1) {
                            return RESTART;
                        }
                    }
                }

                my_snake = snake_grow(my_snake);
                my_apple = make_apple(my_snake);
            }
        }
    }

    return 0;
}

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
