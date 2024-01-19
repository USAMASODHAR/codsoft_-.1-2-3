#include<iostream>
#include<stdlib.h>  // I am including this header for system("cls")
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn= 'X';
int row, column;
int choice;
bool draw=false;

void display_board()
{
	// Using these options to clear the screen and giving color to the screen
    system("cls");
    system("color a");
    
    // Displaying the players
    cout<< "\tPlayer1 [X] \t\nPlayer2 [0]\n\n";

    // Removing cin>>choice; as it is not needed here

    // Displaying the turns to be selected
    cout<< "\t\t     |     |     \n";
    cout<< "\t\t "<<board[0][0]<<"   |  "<<board[0][1]<<"  |  "<<board[0][2]<<"   \n";
    cout<< "\t\t_____|_____|_____\n";
    cout<< "\t\t     |     |     \n";
    cout<< "\t\t "<<board[1][0]<<"   |  "<<board[1][1]<<"  |  "<<board[1][2]<<"   \n";
    cout<< "\t\t_____|_____|_____\n";
    cout<< "\t\t     |     |     \n";
    cout<< "\t\t "<<board[2][0]<<"   |  "<<board[2][1]<<"  |  "<<board[2][2]<<"   \n";
    cout<< "\t\t     |     |     \n";
}

void player_turn()
{
    if(turn =='X')
        cout<< "\n\tPlayer1 [X] turn:";
    else if(turn == '0')
        cout<< "\n\tPlayer2 [0] turn:";

    cin>>choice;

    switch(choice)
    {
    case 1: row=0; column=0;break;
    case 2: row=0; column=1;break;
    case 3: row=0; column=2;break;
    case 4: row=1; column=0;break;
    case 5: row=1; column=1;break;
    case 6: row=1; column=2;break;
    case 7: row=2; column=0;break;
    case 8: row=2; column=1;break;
    case 9: row=2; column=2;break;
    default:
        cout<< "invalid choice\n";
        return; 
    }
    
    // Setting the turns of the players
    if(turn == 'X' && board[row][column]!='X' && board[row][column] != '0')
    {
        board[row][column]='X';
        turn = '0';
    }
    else if(turn == '0'  && board[row][column]!='X' && board[row][column] != '0')
    {
        board[row][column]='0';
        turn = 'X';
    }
    else
    {
        cout<< "That Box is already filled!!!\n please try again!!!!\n";
        player_turn();
    }
    display_board();
}

bool gameover()
{
    // game is won or check winner!!!
    for(int i=0; i<3; i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] || board [0][i]==board[1][i] && board[0][i]==board[2][i])
            return false;
    }

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    // if there is any box remaining
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] != 'X' && board[i][j] != '0')
                return true;
        }
    }

    // draw
    draw=true;
    return false;
}

int main()
{
    while(gameover())
    {
        display_board();
        player_turn();
    }

    if(turn == 'X' && draw == false)
        cout<< "Player2 [0] Wins!! Congrats\n";
    else if(turn == '0' && draw==false)
        cout<< "Player1 [X] Wins!! Congrats\n";
    else
        cout<< "Game is tied!! \n";

    return 0;
}
