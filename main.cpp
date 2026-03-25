#include "game_config.h"
#include "board.h"
#include "player.h"
#include "ai.h"

string board[4][4];
int boardSize;
char turn='X';

int row,column;
bool draw=false;

string player1,player2;
int gameMode;

int score1=0, score2=0, drawScore=0;
int main()
{
    srand(time(0));

    cout<<"Select Game Mode:\n1. Player vs Player\n2. Player vs Computer\nEnter: ";
    cin>>gameMode;

    cout<<"\nSelect Board Size:\n1. 3x3\n2. 4x4\nEnter: ";
    int sizeChoice;
    cin>>sizeChoice;

    boardSize=(sizeChoice==1)?3:4;

    cin.ignore();

    cout<<"\nEnter Player 1 Name (X): ";
    getline(cin,player1);

    if(gameMode==1)
    {
        cout<<"Enter Player 2 Name (0): ";
        getline(cin,player2);
    }
    else
        player2="Computer";

    char playAgain;

    do
    {
        reset_board();

        while(!gameover())
        {
            display_board();
            player_turn();
        }

        if(turn=='X' && !draw)
        {
            cout<<"\n"<<player2<<" Wins!\n";
            score2++;
        }
        else if(turn=='0' && !draw)
        {
            cout<<"\n"<<player1<<" Wins!\n";
            score1++;
        }
        else
        {
            cout<<"\nGAME DRAW!\n";
            drawScore++;
        }

        cout<<"\nPlay Again? (Y/N): ";
        cin>>playAgain;

    }while(playAgain=='Y' || playAgain=='y');

    cout<<"\nFinal Scores:\n";
    cout<<player1<<" : "<<score1<<endl;
    cout<<player2<<" : "<<score2<<endl;
    cout<<"Draws : "<<drawScore<<endl;

    cout<<"\nThanks for playing!\n";
}
