/* Tic-Tac-Toe header, all the functions are listed here                                    */

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <ncurses.h>

#define UP KEY_UP
#define RIGHT KEY_RIGHT
#define DOWN KEY_DOWN
#define LEFT KEY_LEFT
#define CHOOSE 10
#define ESCAPE 27

void restartboard(char place[3][3]);
void printboard();
int comand();
int mainmenu();
int matchendmenu();
void match();
void winner(char place[3][3], int *endround);
void player1(char place[3][3], int *y, int *x, int *py, int *px, int *endround);
void player2(char place[3][3], int *y, int *x, int *py, int *px, int *endround);
int main();

#endif
