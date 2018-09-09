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
void makeMove(char move[3], char board[][3], int turn);
bool replay();

using namespace std;

int main()
{
  //setup
  char board[3][3] = {};
  char move[3];
  int p1wins = 0;
  int p2wins = 0;
  int turn = 1;
  int game = 0;//games played
  
  //play loop
  while (game == 0 || replay())
    {
      game++;
      cout << endl;
      for (int i = 0; i < 3; i++)
	{
	  for (int j = 0; j < 3; j++)
	    {
	      board[i][j] = '-';
	    }
	}
      
      //game loop
      while (!checkWin(board, turn))
	{
	  if (turn > 0)
	    {
	      turn = 0;
	    }
	  else
	    {
	      turn = 1;
	    }
	  
	  printBoard(board, p1wins, p2wins, turn);
	  getMove(move);
	  if (move[0] == 'q')
	    {
	      turn = 2;
	      break;
	    }
	  makeMove(move, board, turn);
	}
  
      //winner
      if (turn == 0)
	{
	  printBoard(board, ++p1wins, p2wins, 2);
	  cout << endl << "Player 1 Wins!";
	}
      else if (turn == 1)
	{
	  printBoard(board, p1wins, ++p2wins, 2);
	  cout << endl << "Player 2 Wins!";
	}
      else
	{
	  cout << endl << "It's a Tie!";
	}
    }
  return 0;
}

//play again query
bool replay()
{
  char ask;
  cout << endl << "Would you like to keep playing? ";
  cin >> ask;
  //cout << "Ask: " << ask;
  if (ask == 'y')
    {
      return true;
    }
  return false;
}

void makeMove(char move[3], char board[][3], int turn)
{
  //2a
  char player = ' ';
  int column = move[0] - 48;
  int row = move[1] - 97;
  //cout << "Row: " << row << "  Column: " << column << endl;
  if (turn == 0)
    {
      player = 'x';
    }
  else
    {
      player = 'o';
    }

  //cout << "Location: " << board[row][column] << endl;
  if (board[row][column] == '-')
    {
      board[row][column] = player;
    }
  else
    {
      cout << endl << "Not a Legal Move." << endl;
    }
  return;
}

void getMove(char move[3])
{
  char input[3];
  cout << endl << "Move: ";
  cin.get(input, sizeof(input));
  cin.get();
  strcpy (move,input);
  return;
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
  else if (turn == 1)
    {
      cout << "Player 2" << endl << endl;
    }
  else
    {
      cout << "-" << endl << endl;
    }
  cout << "  0 1 2" << endl;
  for (int i = 0; i < 3; i++)
    {
      cout << (char)('a' + i);
      for (int j = 0; j < 3; j++)
	{
	  cout << " " << board[i][j];
	}
      cout << endl;
    }
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

