/* Tic-Tac-Toe functions that are menus */

#include "tictactoe.h"

/* Prints and control mainmenu */
int mainmenu(){

	/* Set the event click, for using the mouse */
	MEVENT click;

	int mainmenu = 1,
		y = 5,
		x = 35;

	clear();

	/* Prints the title */
	attron(COLOR_PAIR(6));
	mvprintw(1, 34, "-------------");
	mvprintw(2, 35, "TIC-TAC-TOE");
	mvprintw(3, 34, "-------------");
	attroff(COLOR_PAIR(6));
	/* Prints the options */
	attron(COLOR_PAIR(1));
	mvprintw(5, 35, "Play   ");
	mvprintw(6, 35, "Options");
	mvprintw(7, 35, "Exit   ");
	attroff(COLOR_PAIR(1));

	/* Moves to the first menu's option */
	move(y, x);

	/* Controls the movement, choosing and the output of the function */
	while(mainmenu){
		switch (command()) {
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

			case KEY_MOUSE:
				if (getmouse(&click) == OK){
					if (click.bstate == BUTTON1_CLICKED){
						if (click.x >= 35 && click.x <= 41 && click.y >= 5 && click.y <= 7){
							move(click.y, x);
							return click.y;
						}
					}
				}
			break;

			case CHOOSE:
				return y;
			break;
		}
	}
}

/* Shows up the first menu for choosing and returns the watever is choosed */
int matchendmenu(){

	int matchendmenu = 1,
		y = 11,
		x = 1;

	/* Move to the bottom and deletes the two lines that gives instructions */
	move(11, 1);
	deleteln();
	deleteln();

	/* Then prints the menu where the instructions were */
	attron(COLOR_PAIR(1));
	mvprintw(11, 1, "Play again");
	mvprintw(12, 1, "Main menu");
	attroff(COLOR_PAIR(1));

	/* Moves to the first option of the menu */
	move(y, x);

	/* Controls the movement, choosing and the output of the function */
	while(matchendmenu){
		switch (command()) {
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
