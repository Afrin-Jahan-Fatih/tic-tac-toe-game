#pragma once

#include "game_config.h"

void computer_turn()
{
    int choice;

    while(true)
    {
        choice = rand()%(boardSize*boardSize)+1;
        row=(choice-1)/boardSize;
        column=(choice-1)%boardSize;

        if(board[row][column]!="X" && board[row][column]!="0")
            break;
    }

    cout<<"\nComputer chooses: "<<choice<<endl;
    board[row][column]="0";
    turn='X';
}
