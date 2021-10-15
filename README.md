# UCFK4 Nokia Snake
This game was written by Francis Phan and Richard Li as an assignment for ENCE260 Embedded Systems in 2021, for the UC Fun Kit 4. 

Before it could be played, it is necessary that the UCFK4 drivers and documents are on your computer. If you have not had them already, they can be cloned by using the command `git clone https://eng-git.canterbury.ac.nz/mph/ence260-ucfk4`.

Once you have got the drivers cloned, change your directory to `assignment/final` and then clone this repository inside that directory.

Make sure your ENCE260 UC Fun Kit 4 has been plugged into the computer. From there, run the following commands to compile the code and load it onto your UCFK4:
1. `make clean`
2. `make program`

## How to play

1. The game starts with sliding words of "Welcome to Snake". It is here that the navswitch should be pressed to start the game. The player snake will appear of length 2, as well as a one-dot apple.

2. Use the navswitch to navigate the snake's head through to the apple. Once it has consumed an apple it will grow by one unit of length.

3. Game is over and you lose when the snake accidentally touches any part of itself or any of the edges of the screen. However, you will win if the snake is able to eat 10 apples. The game will conclude there, with sliding words of "You lost" or "You won". The original menu "Welcome to Snake" is then displayed and should you want to play the game again, press the navswitch to restart.


## Technical Description
There are four main files with their associated header files of the same names:
* snake.c and snake.h
* messages.c and message.h