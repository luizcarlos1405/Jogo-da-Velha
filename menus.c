#include "tictactoe.h"

/***** Print and control mainmenu **************/
int mainmenu(){

	initscr(); /* para chamar ncurses */
	noecho();
	keypad(stdscr, TRUE);
	cbreak();

	int mainmenu = 1,
		y = 5,
		x = 35;

	clear();

	/***** Prints the title ******************/
	mvprintw(1, 34, "-------------");
    mvprintw(2, 35, "TIC-TAC-TOE");
    mvprintw(3, 34, "-------------");

	/***** Prints the optcions****************/
	mvprintw(5, 35, "Play");
	mvprintw(6, 35, "Options");
	mvprintw(7, 35, "Exit");

	move(y, x);

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

/***** Shows up the first menu for choosing ****
 * and return the option ***********************/
int matchendmenu(){

	int matchendmenu = 1,
		y = 11,
		x = 1;

	move(11, 1);
	deleteln();
	deleteln();

	mvprintw(11, 1, "Play again");
	mvprintw(12, 1, "Main menu");

	move(y, x);

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
