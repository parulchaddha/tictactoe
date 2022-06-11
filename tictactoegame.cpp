// tic tac toe game
//#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define COMPUTER 1
#define HUMAN 2
#define SIDE 3 // length of board
// computer will move wd O and human with X
#define COMPUTERMOVE 'O'
#define HUMANMOVE 'X'
// A function to show the current board status
void SHOWBOARD(char board[][SIDE])
{
    printf("\n\n");
    printf("\t\t\t %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t ----|------|----  \n");
    printf("\t\t\t %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t ----|------|----  \n");
    printf("\t\t\t %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    return;
}
// A function to show the instructions
void SHOWINSTRUCTIONS()
{
    printf("\t\t\t TIC-TAC-TOE\n\n");
    printf("choose a cell numbered from 1 to 9 as below and play \n\n");
    printf("\t\t\t  1  |   2  |  3   \n");
    printf("\t\t\t ----|------|----  \n");
    printf("\t\t\t  4  |   5  |   6  \n");
    printf("\t\t\t ----|------|----  \n");
    printf("\t\t\t  7  |   8  |   9  \n\n");
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
    return;
}
// A function to initialise the game
void initialise(char board[][SIDE], int moves[])
{
    // initialise random number generator to avoid same configuration
    srand (time(NULL));
    // Initially the board is empty
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            board[i][j] = ' ';
        }
    }
    // fill moves with numbers
    for (int i = 0; i < SIDE * SIDE; i++)
    {
        moves[i] = i;
    }
    // randomise the moves
    random_shuffle(moves, moves + SIDE * SIDE);
    return;
}
// A function to declare winner of the game
void declarewinner(int whoseturn)
{
    if (whoseturn == COMPUTER)
        printf("COMPUTER has won\n");
    else
        printf("HUMAN has won\n");
    return;
}
// A function that return true if any of the row is crossed wd same player's move
bool rowcross(char board[][SIDE])
{
    for (int i = 0; i < SIDE; i++)
    {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != ' '))
            return true;
    }
    return(false);
}
// A function that return true if any of the coloumn is crossed wd same player's move
bool coloumncross(char board[][SIDE])
{
    for (int i = 0; i < SIDE; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return(true);
    }
    return(false);
}
// A function that return true if any of the diagonal is crossed wd same player's move
bool diagonalcross(char board[][SIDE])
{
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return(true);
    return(false);
}
// A function that return true if the game is over
bool gameover(char board[][SIDE])
{
    return rowcross(board) || coloumncross(board) || diagonalcross(board);
}
// a function to play tic tac toe
void playtictactoe(int whoseturn)
{
    // a 3*3 tic tac toe board for playing
    char board[SIDE][SIDE];
    int moves[SIDE * SIDE];
    // initialise the game
    initialise(board, moves);
    // show the instructions before playing
    SHOWINSTRUCTIONS();
    int moveindex = 0, x, y;
    // keep playing till the game is over or it is draw
    while (gameover(board) == false && moveindex != SIDE * SIDE)
    {
        if (whoseturn == COMPUTER)
        {
            x = moves[moveindex] / SIDE;
            y = moves[moveindex] % SIDE;
            board[x][y] = COMPUTERMOVE;
            printf("COMPUTER has put a %c in cell %d\n", COMPUTERMOVE, moves[moveindex] + 1);
            SHOWBOARD(board);
            moveindex++;
            whoseturn = HUMAN;
        }
        else if (whoseturn == HUMAN)
        {
            x = moves[moveindex] / SIDE;
            y = moves[moveindex] % SIDE;
            board[x][y] = HUMANMOVE;
            printf("HUMAN has put a %c in cell %d\n", HUMANMOVE, moves[moveindex] + 1);
            SHOWBOARD(board);
            moveindex++;
            whoseturn = COMPUTER;
        }
    }
    // if the game has drawn
    if (gameover(board) == false && moveindex == SIDE * SIDE)
    {
        printf("IT'S A DRAW");
    }
    else
    {
        // toggling the user to declare the actual winner
        if (whoseturn == COMPUTER)
        {
            whoseturn = HUMAN;
        }
        else if (whoseturn == HUMAN)
        {
            whoseturn = COMPUTER;
        }
        declarewinner(whoseturn);
    }
    return;
}
// driver program
int main()
{
    // let us play with computer starting first
    playtictactoe(COMPUTER);
    return (0);
}