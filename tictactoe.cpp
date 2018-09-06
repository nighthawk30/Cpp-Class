/*
Nathan Taylor
Tic Toe Tac Console Based Game
9/8/2018
 */
#include <iostream>
#include <cstring>

void printBoard(char board[][3], int p1, int p2, int turn);

using namespace std;

int main()
{
  char board[3][3] = {};
  int p1wins = 0;
  int p2wins = 0;
  int turn = 0;
  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
	{
	  board[i][j] = 'o';
	}
    }
  printBoard(board, p1wins, p2wins, turn);
  return 0;
}

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
