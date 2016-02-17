#include "tictactoe.h"

/***** Put charactere ' ' into every place of
 * the array place                ************/
void restartboard(char place[3][3]){
    int i,
        j;
    for ( i = 0; i < 3 ; i++){
        for ( j = 0; j < 3 ; j++){
            place[i][j] = ' ';
		}
    }
}

/***** Prints the board on terminal */
void printboard(){

    clear();

    /***** Prints the title ******************/
	mvprintw(1, 34, "-------------");
    mvprintw(2, 35, "TIC-TAC-TOE");
    mvprintw(3, 34, "-------------");

    /***** Prints the board ******************/
	mvprintw(5, 38, " | | ");
    mvprintw(6, 38, "-----");
    mvprintw(7, 38, " | | ");
    mvprintw(8, 38, "-----");
    mvprintw(9, 38, " | | ");

	/***** Prints instructions ***************/
    mvprintw(11, 0, "Use arrow keys to move and 'Enter' for choosing the place.");

    mvprintw(12, 0, "'Esc' to leave.");
}

/** Get a char from the keyboard and return it*/
int comand(){
    int comand;
    comand = getch();
    return comand;
}

/***** Commands everything for long as the 'X' *
* player is in his turn **********************/
void player1(char place[3][3], int *y, int *x, int *py, int *px, int *endround){

    int  turn = 1;

	while (turn){

	    switch(comand()){
	        case UP:
	            if(*y > 5){
					*y = *y - 2;
					*py = *py - 1;
	                move(*y, *x);
	            }
	        break;

	        case LEFT:
                if(*x > 38){
					*x = *x - 2;
					*px = *px - 1;
                    move(*y, *x);
                }
            break;

	        case DOWN:
                if (*y < 9){
                    *y = *y + 2;
					*py = *py + 1;
					move(*y, *x);
                }
            break;

	        case RIGHT:
                if (*x < 42){
					*x = *x + 2;
					*px = *px + 1;
                    move(*y, *x);
                }
            break;

	        case CHOOSE:
				if (place[*py][*px] == ' '){
					printw("X");
					place[*py][*px] = 'X';
					move(*y, *x);
					turn = 0;
				}
            break;

	        case ESCAPE:
				turn = 0;
				*endround = 0;
            break;
        }
    }
}

/***** Commands everything for long as the 'O' *
* player is in his turn **********************/
void player2(char place[3][3], int *y, int *x, int *py, int *px, int *endround){

    int  turn = 1;

	while (turn){

	    switch(comand()){
	        case UP:
	            if(*y > 5){
					*y = *y - 2;
					*py = *py - 1;
	                move(*y, *x);
	            }
	        break;

	        case LEFT:
                if(*x > 38){
					*x = *x - 2;
					*px = *px - 1;
                    move(*y, *x);
                }
            break;

	        case DOWN:
                if (*y < 9){
                    *y = *y + 2;
					*py = *py + 1;
					move(*y, *x);
                }
            break;

	        case RIGHT:
                if (*x < 42){
					*x = *x + 2;
					*px = *px + 1;
                    move(*y, *x);
                }
            break;

	        case CHOOSE:
				if (place[*py][*px] == ' '){
					printw("O");
					place[*py][*px] = 'O';
					move(*y, *x);
					turn = 0;
				}
            break;

	        case ESCAPE:
				turn = 0;
				*endround = 0;
            break;
        }
    }
}

/***** Tests if somebody won the match. I found*
 * no other way to test, but this **************/
void winner(char place[3][3], int *endround){

    if ((place[0][0]==place[0][1]&&place[0][0]==place[0][2]&&place[0][0]=='X')||(place[1][0]==place[1][1]&&place[1][0]==place[1][2]&&place[1][0]=='X')||(place[2][0]==place[2][1]&&place[2][0]==place[2][2]&&place[2][0]=='X')||(place[0][0]==place[1][0]&&place[0][0]==place[2][0]&&place[0][0]=='X')||(place[0][1]==place[1][1]&&place[0][1]==place[2][1]&&place[0][1]=='X')||(place[0][2]==place[1][2]&&place[0][2]==place[2][2]&&place[0][2]=='X')||(place[0][0]==place[1][1]&&place[0][0]==place[2][2]&&place[0][0]=='X')||(place[0][2]==place[1][1]&&place[0][2]==place[2][0]&&place[0][2]=='X')){
        *endround = 4;
    }

    else if ((place[0][0]==place[0][1]&&place[0][0]==place[0][2]&&place[0][0]=='O')||(place[1][0]==place[1][1]&&place[1][0]==place[1][2]&&place[1][0]=='O')||(place[2][0]==place[2][1]&&place[2][0]==place[2][2]&&place[2][0]=='O')||(place[0][0]==place[1][0]&&place[0][0]==place[2][0]&&place[0][0]=='O')||(place[0][1]==place[1][1]&&place[0][1]==place[2][1]&&place[0][1]=='O')||(place[0][2]==place[1][2]&&place[0][2]==place[2][2]&&place[0][2]=='O')||(place[0][0]==place[1][1]&&place[0][0]==place[2][2]&&place[0][0]=='O')||(place[0][2]==place[1][1]&&place[0][2]==place[2][0]&&place[0][2]=='O')){
        *endround = 4;
	}

    else if (place[0][0]!=' '&&place[0][1]!=' '&&place[0][2]!=' '&&place[1][0]!=' '&&place[1][1]!=' '&&place[1][2]!=' '&&place[2][0]!=' '&&place[2][1]!=' '&&place[2][2]!=' '){
        *endround = 3;
    }
}

/***** When there is a match going on **********/
void match(){
	int y = 7,
	    x = 40,
		py = 1,
		px = 1; // variables to control the values of the place array

	int match = 11,
		endround;

    char shift = 'X',
		 place[3][3];

    while (match != 12){

		restartboard(place);
		clear();
		printboard();
		move(y, x);

		endround = 1;

        while (endround == 1){

			switch(shift){
				case 'X':
					player1(place, &y, &x, &py, &px, &endround);
					winner(place, &endround);
					if (endround == 1)
						shift = 'O';
					else if (endround == 3){
						move(11, 1);
						deleteln();
						deleteln();
						mvprintw(11, 35, "Its a tie!", shift);
						getch();
						match = matchendmenu();
					}

					else if (endround == 4){
						move(11, 1);
						deleteln();
						deleteln();
						mvprintw(11, 33, "Player '%c' won!", shift);
						getch();
						match = matchendmenu();
					}

					else
				    	match = matchendmenu();
				break;

				case 'O':
					player2(place, &y, &x, &py, &px, &endround);
					winner(place, &endround);
					if (endround == 1)
						shift = 'X';
					else if (endround == 3){
						move(11, 1);
						deleteln();
						deleteln();
						mvprintw(11, 35, "Its a tie!", shift);
						getch();
						match = matchendmenu();
					}

					else if (endround == 4){
						move(11, 1);
						deleteln();
						deleteln();
						mvprintw(11, 33, "Player '%c' won!", shift);
						getch();
						match = matchendmenu();
					}

					else
				    	match = matchendmenu();
				break;
			}
        }
    }
}
