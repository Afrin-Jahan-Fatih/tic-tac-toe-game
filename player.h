#pragma once

#include "game_config.h"
#include "ai.h"

void player_turn()
{
    int choice;

    if(gameMode==2 && turn=='0')
    {
        computer_turn();
        Sleep(1500);
        display_board();
        return;
    }

    if(turn=='X')
        cout<<"\n"<<player1<<" [X] turn: ";
    else
        cout<<"\n"<<player2<<" [0] turn: ";

    cin>>choice;

    if(choice<1 || choice>boardSize*boardSize)
    {
        cout<<"Invalid choice!\n";
        player_turn();
        return;
    }

    row=(choice-1)/boardSize;
    column=(choice-1)%boardSize;

    if(board[row][column]!="X" && board[row][column]!="0")
    {
        board[row][column]=string(1,turn);
        turn=(turn=='X')?'0':'X';
    }
    else
    {
        cout<<"Box already filled!\n";
        player_turn();
    }

    display_board();
}
