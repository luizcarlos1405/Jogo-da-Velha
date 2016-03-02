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

	initscr();
	noecho();
	keypad(stdscr, TRUE);
	cbreak();

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
