# File:   Makefile
# Author: Francis Phan, Richard Li
# Date:   16 October 2021
# Descr:  Makefile for the slithering Program

# Definitions
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I../../drivers/avr -I../../fonts -I../../drivers -I../../utils -I../../extra
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: slithering.out


# Compile: create object files from C source files.

slithering.o: slithering.c ../../drivers/avr/system.h ../../drivers/display.h ../../drivers/navswitch.h ../../fonts/font3x5_1.h ../../utils/font.h ../../utils/pacer.h ../../utils/tinygl.h ../../extra/mmelody.h ../../extra/ticker.h ../../extra/tweeter.h ../../utils/task.h
	$(CC) -c $(CFLAGS) $< -o $@

game.o: game.c ../../drivers/avr/system.h ../../drivers/display.h ../../drivers/navswitch.h ../../fonts/font3x5_1.h ../../utils/font.h ../../utils/pacer.h ../../utils/tinygl.h ../../extra/mmelody.h ../../extra/ticker.h ../../extra/tweeter.h ../../utils/task.h
	$(CC) -c $(CFLAGS) $< -o $@

messages.o: messages.c ../../drivers/avr/system.h ../../drivers/display.h ../../drivers/navswitch.h ../../fonts/font3x5_1.h ../../utils/font.h ../../utils/pacer.h ../../utils/tinygl.h ../../extra/mmelody.h ../../extra/ticker.h ../../extra/tweeter.h ../../utils/task.h
	$(CC) -c $(CFLAGS) $< -o $@


task.o: ../../utils/task.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../utils/task.h
	$(CC) -c $(CFLAGS) $< -o $@

pio.o: ../../drivers/avr/pio.c ../../drivers/avr/pio.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../drivers/avr/system.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

timer.o: ../../drivers/avr/timer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

display.o: ../../drivers/display.c ../../drivers/avr/system.h ../../drivers/display.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

ledmat.o: ../../drivers/ledmat.c ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

navswitch.o: ../../drivers/navswitch.c ../../drivers/avr/delay.h ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/navswitch.h
	$(CC) -c $(CFLAGS) $< -o $@

font.o: ../../utils/font.c ../../drivers/avr/system.h ../../utils/font.h
	$(CC) -c $(CFLAGS) $< -o $@

pacer.o: ../../utils/pacer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@

tinygl.o: ../../utils/tinygl.c ../../drivers/avr/system.h ../../drivers/display.h ../../utils/font.h ../../utils/tinygl.h
	$(CC) -c $(CFLAGS) $< -o $@

ir_uart.o: ../../drivers/avr/ir_uart.c ../../drivers/avr/ir_uart.h ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/avr/timer0.h ../../drivers/avr/usart1.h
	$(CC) -c $(CFLAGS) $< -o $@

ticker.o: ../../extra/ticker.c
	$(CC) -c $(CFLAGS) $< -o $@

# Link: create output file (executable) from object files.
slithering.out: slithering.o messages.o game.o mmelody.o pio.o system.o timer.o display.o ledmat.o navswitch.o font.o pacer.o tinygl.o ticker.o tweeter.o task.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Create hex file for programming from executable file.
slithering.hex: slithering.out
	$(OBJCOPY) -O ihex slithering.out slithering.hex


# Target: clean project.
.PHONY: clean
clean: 
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: slithering.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash slithering.hex; dfu-programmer atmega32u2 start
