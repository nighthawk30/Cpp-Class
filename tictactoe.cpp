/*
Nathan Taylor
Tic Toe Tac Console Based Game
9/8/2018
 */

/*
  0 1 2
a - - -
b - - -
c - - -
 */
#include <iostream>
#include <cstring>

void printBoard(char board[][3], int p1, int p2, int turn);
bool checkWin(char board[][3], int turn);
void getMove(char move[3]);

using namespace std;

int main()
{
  char board[3][3] = {};
  char move[2];
  int p1wins = 0;
  int p2wins = 0;
  int turn = 0;
  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
	{
	  board[i][j] = '-';
	}
    }
  printBoard(board, p1wins, p2wins, turn);
  getMove(move);
  cout << move;
  return 0;
}

void getMove(char move[2])
{
  char input[3];
  cout << endl << "Move: ";
  cin.get(input, sizeof(input));
  cin.get();
  strcpy (move,input);
  return;
}

//checks if a player has made a winning move
bool checkWin(char board[][3], int turn)
{
  char player = ' ';
  bool win = false;
  int linescore = 0;
  
  if (turn == 0)
    {
      player = 'x';
    }
  else
    {
      player = 'o';
    }

  //horizontal a,b,c
  for (int i = 0; i < 3; i++)
    {
      linescore = 0;
      for (int j = 0; j < 3; j++)
	{
	  if (board[i][j] == player)
	    {
	      linescore++;
	    }
	}
      if (linescore == 3)
	{
	  win = true;
	}
    }

  //vertical 1,2,3
  for (int j = 0; j < 3; j++)
    {
      linescore = 0;
      for (int i = 0; i < 3; i++)
	{
	  if (board[i][j] == player)
	    {
	      linescore++;
	    }
	}
      if (linescore == 3)
	{
	  win = true;
	}
    }

  //diagonal 1a,2b,3c
  linescore = 0;
  for (int i = 0; i < 3; i++)
    {
      if (board[i][i] == player)
	{
	  linescore++;
	}
    }

  if (linescore == 3)
    {
      win = true;
    }

  //diagonal 1c,2b,3a
  linescore = 0;
  for (int i = 0; i < 3; i++)
    {
      if (board[i][2-i] == player)
	{
	  linescore++;
	}
    }

  if (linescore == 3)
    {
      win = true;
    }
  
  return win;
}

//prints out the board and game state to the console
void printBoard(char board[][3], int p1, int p2, int turn)
{
  cout << endl << "Player 1: " << p1 << "   Player 2: " << p2 << endl;
  cout << "Turn: ";
  if (turn == 0)
    {
      cout << "Player 1" << endl << endl;
    }
  else
    {
      cout << "Player 2" << endl << endl;
    }
  cout << "  0 1 2" << endl;
  for (int i = 0; i < 3; i++)
    {
      cout << (char)('a' + i) << " ";
      for (int j = 0; j < 3; j++)
	{
	  cout << board[i][j] << " ";
	}
      cout << endl;
    }
  return;
}
