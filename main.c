/******************************************************************************
* Game Tic-Tac-Toe I.M. 2.0 by Luiz Carlos L. G. de Oliveira				  *
*																			  *
* You're free to modify at your will and share if want to. I've developed this*
* Game Tic-Tac-Toe I.M. 2.0 by Luiz Carlos L. G. de Oliveira		          *
*									                                          *
* Feel free to modify at your will and share if want to. I've developed this  *
* for practice.                                                               *
* This update includes library ncurses.                                       *
* 									                                          *
* Contact: luizcarlos1405@gmail.com                 					      *
*                                    									      *
*                                                                             *
* Programa Jogo-da-Velha M.I. 2.0 criado por Luiz Carlos L. G. de Oliveira    *
*                                                                             *
* Sinta-se livre para modificar e compartilhar caso queira. Desenvolvi este   *
* jogo para fins de prática apenas. Acabei me empolgando.                     *
* Essa atualização inclui a utilização da biblioteca ncurses.                 *
*																			  *
* Contato: luizcarlos1405@gmail.com                                           *
*																			  *
******************************************************************************/

#include <stdio.h>
#include <ncurses.h>
#include "tictactoe.h"

int main(){
	/* Set the event click, for using the mouse */
	MEVENT click;
	/* Starts curses screen */
	initscr();
	/* Allows to set colors */
	start_color();
	/* Diseable echoes */
	noecho();
	/* Allows to use KEY_* constants */
	keypad(stdscr, TRUE);
	cbreak();
	/* Start a mask for all mouse events, wich allows to use'em */
	mousemask(ALL_MOUSE_EVENTS, NULL);
	/* Set the colors */
	init_pair(1, 1, COLOR_BLACK); // Red
	init_pair(2, 2, COLOR_BLACK); // Green
	init_pair(3, 3, COLOR_BLACK); // Yellow
	init_pair(4, 4, COLOR_BLACK); // Blue
	init_pair(5, 5, COLOR_BLACK); // Magenta
	init_pair(6, 6, COLOR_BLACK); // Cyan
	init_pair(7, 0, COLOR_WHITE); // Black
	/* The game */
	int program = 1;
	while (program){
		switch (mainmenu()){
			case 5:
				match();
			break;
			case 7:
				program = 0;
			break;
		}
	}

	endwin();

    return 0;
}
