/* Tic-Tac-Te functions that are menus                             */

#include "tictactoe.h"

/* Print and control mainmenu */
int mainmenu(){

	/* Iniciates ncurses screan */
	initscr();
	/* Desable echoes from terminal */
	noecho();
	/* Allows to use KEY_* constants */
	keypad(stdscr, TRUE);
	cbreak();

	int mainmenu = 1,
		y = 5,
		x = 35;

	clear();

	/* Prints the title */
	mvprintw(1, 34, "-------------");
    mvprintw(2, 35, "TIC-TAC-TOE");
    mvprintw(3, 34, "-------------");

	/* Prints the optcions****/
	mvprintw(5, 35, "Play");
	mvprintw(6, 35, "Options");
	mvprintw(7, 35, "Exit");

	/* Moves to the first option of the menu */
	move(y, x);

	/* Controls the movement, choosing and the output of the function */
	while(mainmenu){
		switch (comand()) {
			case UP:
				if (y > 5){
					y--;
					move(y, x);
				}
			break;

			case DOWN:
				if (y < 7){
					y++;
					move(y, x);
				}
			break;

			case CHOOSE:
				return y;
			break;
		}
	}
}

/* Shows up the first menu for choosing and return the option */
int matchendmenu(){

	int matchendmenu = 1,
		y = 11,
		x = 1;

	/* Move to the bottom and deletes the two lines that gives instructions */
	move(11, 1);
	deleteln();
	deleteln();

	/* Then prints the menu where the instructions were */
	mvprintw(11, 1, "Play again");
	mvprintw(12, 1, "Main menu");

	/* Moves to the first option of the menu */
	move(y, x);

	/* Controls the movement, choosing and the output of the function */
	while(matchendmenu){
		switch (comand()) {
			case UP:
				if (y > 11){
					y--;
					move(y, x);
				}
			break;

			case DOWN:
				if (y < 12){
					y++;
					move(y, x);
				}
			break;

			case CHOOSE:
				return y;
		}
	}
}
