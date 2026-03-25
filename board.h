#pragma once

#include "game_config.h"
void reset_board()
{
    int start=1;

    for(int i=0;i<boardSize;i++)
        for(int j=0;j<boardSize;j++)
            board[i][j]=to_string(start++);

    turn='X';
    draw=false;
}

void display_board()
{
    system("cls");

    cout<<"\n        T I C K   C R O S S\n\n";
    cout<<player1<<" [X]\n"<<player2<<" [0]\n\n";

    cout<<"Board Size: "<<boardSize<<" x "<<boardSize<<"\n\n";

    cout<<"Scoreboard:\n";
    cout<<player1<<" : "<<score1<<endl;
    cout<<player2<<" : "<<score2<<endl;
    cout<<"Draws : "<<drawScore<<"\n\n";

    for(int i=0;i<boardSize;i++)
    {
        cout<<"\t";
        for(int j=0;j<boardSize;j++)
        {
            cout<<" "<<board[i][j]<<" ";
            if(j<boardSize-1) cout<<"|";
        }
        cout<<endl;

        if(i<boardSize-1)
        {
            cout<<"\t";
            for(int k=0;k<boardSize;k++)
                cout<<"----";
            cout<<endl;
        }
    }
}
bool gameover()
{
    // Rows
    for(int i=0;i<boardSize;i++)
    {
        bool win=true;
        for(int j=1;j<boardSize;j++)
            if(board[i][0]!=board[i][j]) win=false;

        if(win) return true;
    }

    // Columns
    for(int i=0;i<boardSize;i++)
    {
        bool win=true;
        for(int j=1;j<boardSize;j++)
            if(board[0][i]!=board[j][i]) win=false;

        if(win) return true;
    }

    // Main Diagonal
    bool win=true;
    for(int i=1;i<boardSize;i++)
        if(board[0][0]!=board[i][i]) win=false;
    if(win) return true;

    // Opposite Diagonal
    win=true;
    for(int i=1;i<boardSize;i++)
        if(board[0][boardSize-1]!=board[i][boardSize-1-i]) win=false;
    if(win) return true;

    // Draw
    for(int i=0;i<boardSize;i++)
        for(int j=0;j<boardSize;j++)
            if(board[i][j]!="X" && board[i][j]!="0")
                return false;

    draw=true;
    return true;
}
