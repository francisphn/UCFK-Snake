/**
 * Program: UCFK4 Snake
 * Module: Header file game.h for game module game.h
 * Authors: Francis Phan, Richard Li
 */


#ifndef GAME_H
#define GAME_H

// The definition of constants
#define PACER_RATE 500
#define LOOP_RATE 500
#define MESSAGE_RATE 20
#define BUTTON_RATE 300
#define LED_ON 1
#define LED_OFF 0

#define MENU_MSG "SNAKE\0"
#define WIN_MSG "WELL PLAYED \0"
#define LOSE_MSG "YOU LOST \0"


// Signatures
int msg_paced_loop(void);
int welcome_msg(void);
int win_msg(void);
int lose_msg(void);

#endif