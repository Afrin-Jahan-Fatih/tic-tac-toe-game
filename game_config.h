#pragma once

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;

extern string board[4][4];
extern int boardSize;
extern char turn;

extern int row,column;
extern bool draw;

extern string player1,player2;
extern int gameMode;

extern int score1, score2, drawScore;
