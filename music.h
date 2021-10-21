/**
 * Program: UCFK4 Snake
 * Module: Header file for music.h
 * Authors: Francis Phan, Richard Li
**/

#ifndef MUSIC_H
#define MUSIC_H

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

#include "pio.h"
#include "task.h"
#include "tweeter.h"
#include "mmelody.h"

/* Connect piezo tweeter to outermost pins of UCFK4 P1 connector.  */
#define PIEZO_PIO PIO_DEFINE (PORT_D, 6)

/* Define polling rates in Hz.  */
#define TWEETER_TASK_RATE 20000
#define TUNE_TASK_RATE 100
#define TUNE_BPM_RATE 200

void tweeter_task_init (void);
void tweeter_task (__unused__ void *data);
void tune_task_init(void);
void tune_task_init_snake(void);
void tune_task_init_wellplayed(void);
void tune_task_init_gameover(void);
void tune_task (__unused__ void *data);

#endif /* MUSIC_H */