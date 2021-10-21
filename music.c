/**
 * Program: UCFK4 Snake
 * Module: game.c
 * Authors: Francis Phan, Richard Li
 * Description: Play some tunes.
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

#include "pio.h"
#include "task.h"
#include "tweeter.h"
#include "mmelody.h"

#include "music.h"

static tweeter_scale_t scale_table[] = TWEETER_SCALE_TABLE (TWEETER_TASK_RATE);
static tweeter_t tweeter;
static mmelody_t melody;
static mmelody_obj_t melody_info;
static tweeter_obj_t tweeter_info;


const char tune1[] =
{
#include "apple.mmel"
//#include "are_friends_electric.mmel"
"    >"
};

const char tune2[] =
{
#include "snake.mmel"
//#include "are_friends_electric.mmel"
"    >"
};

const char tune3[] =
{
#include "wellplayed.mmel"
//#include "are_friends_electric.mmel"
"    >"
};

const char tune4[] =
{
#include "gameover.mmel"
//#include "are_friends_electric.mmel"
"    >"
};


void tweeter_task_init (void)
{
    tweeter = tweeter_init (&tweeter_info, TWEETER_TASK_RATE, scale_table);

    pio_config_set (PIEZO_PIO, PIO_OUTPUT_LOW);
}


void tweeter_task (__unused__ void *data)
{
    pio_output_set (PIEZO_PIO, tweeter_update (tweeter));
}


void tune_task_init(void)
{
    melody = mmelody_init (&melody_info, TUNE_TASK_RATE, 
			   (mmelody_callback_t) tweeter_note_play, tweeter);

    mmelody_speed_set (melody, TUNE_BPM_RATE);

    mmelody_play (melody, tune1);
}

void tune_task_init_snake(void)
{
    melody = mmelody_init (&melody_info, TUNE_TASK_RATE, 
			   (mmelody_callback_t) tweeter_note_play, tweeter);

    mmelody_speed_set (melody, TUNE_BPM_RATE);

    mmelody_play (melody, tune2);
}

void tune_task_init_wellplayed(void)
{
    melody = mmelody_init (&melody_info, TUNE_TASK_RATE, 
			   (mmelody_callback_t) tweeter_note_play, tweeter);

    mmelody_speed_set (melody, TUNE_BPM_RATE);

    mmelody_play (melody, tune3);
}

void tune_task_init_gameover(void)
{
    melody = mmelody_init (&melody_info, TUNE_TASK_RATE, 
			   (mmelody_callback_t) tweeter_note_play, tweeter);

    mmelody_speed_set (melody, TUNE_BPM_RATE);

    mmelody_play (melody, tune4);
}

void tune_task (__unused__ void *data)
{
    mmelody_update (melody);
}