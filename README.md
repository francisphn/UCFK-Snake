# UCFK4 Nokia Snake
This game was written by Francis Phan and Richard Li as an assignment for ENCE260 Embedded Systems in 2021, for the UC Fun Kit 4. 

Before it could be played, it is necessary that the UCFK4 drivers and documents are on your computer. If you have not had them already, they can be cloned by using the command `git clone https://eng-git.canterbury.ac.nz/mph/ence260-ucfk4`.

Once you have got the drivers cloned, change your directory to `/assignment/` and then clone this repository inside that directory. Then change your directory to  `/group_509/`

Make sure your ENCE260 UC Fun Kit 4 has been plugged into the computer. From there, run the following commands to compile the code and load it onto your UCFK4:
1. `make clean`
2. `make`
2. `make program`

## How to play
The orientation of the matrix is vertical such that the USB port is at the top of the UCFK4, and this fact is reflected in the code of the game. However, you should rotate the UCFK4 so that the USB port is on your right hand side.

1. After `make program` has been run, the game starts with sliding words of "Snake". Press the navswitch down, then use the navswitch (turning left or right) to select the level of the game. There are three difficulty levels: Level 1, Level 2 and Level 3. Once you have selected your desired difficulty, press the navswitch down one more time.

2. The game starts with a snake that has a head. Use the navswitch to navigate the snake's head through to the apple. Once it has consumed an apple it will grow by one unit of length.

3. Game is over and you lose when the snake accidentally touches any part of itself or any of the edges of the screen. However, you will win if the snake is able to eat 10 apples. The game will conclude there, with sliding words of "Well played" or "Game over". Here, you can restart the program by pressing the navswitch down to return to the original menu with the sliding word "Snake".


## Complexity Description
We've added some complexity into the program for extra marks.
1. There is music at the start and at the end of the game, according to how you did, and when the snake turns.
2. The turning of the snake is a complex process involving many loops.
3. Pressing Game over lets you know how well you did - your score - printing variable to output.
4. It is possible to restart the game from the Game Over Menu, rather than having to run `make program` again.
5. There are different levels: 1, 2 and 3. The higher the level, the acceleration of the snake will increase after each apple is eaten.
6. The snake dies when it collides with itself, or any of the boundary.