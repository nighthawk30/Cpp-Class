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
void doMove(char board[][3], int turn, bool& quit);
bool checkTie(char board[][3]);
bool replay();

using namespace std;

int main()
{
  //setup
  char board[3][3] = {};
  bool quit = false;
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
	  //tie checker
	  if(checkTie(board))
	    {
	      turn = 2;
	      break;
	    }

	  if (turn > 0)
	    {
	      turn = 0;
	    }
	  else
	    {
	      turn = 1;
	    }
	  //while (cin.get() != '\n');	  
	  printBoard(board, p1wins, p2wins, turn);
	  doMove(board, turn, quit);
	  //while (cin.get() != '\n');
	  if (quit)
	    {
	      turn = 3;
	      quit = false;
	      break;
	    }
	  //moves++;
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
      else if (turn == 2)
	{
	  printBoard(board, p1wins, p2wins, 2);
	  cout << endl << "It's a Tie!";
	}
    }
  return 0;
}

//play again query
bool replay()
{
  char ask[10];
  cout << endl << "Would you like to keep playing? ";
  cin.getline(ask, sizeof(ask));
  cout << "__________________________________";
  if (ask[0] == 'y')
    {
      return true;
    }
  return false;
}

void doMove(char board[][3], int turn, bool& quit)
{
  char row = ' ';
  char column = ' ';
  bool query = true;
  
  while (query)
    {
      //while (cin.get() != '\n');
      while (row != 'a' && row != 'b' && row != 'c' && row != 'q')
	{
	  cout << endl << "Row: ";
	  cin >> row;
	  cin.get();
	}
      if (row == 'q')
	{
	  quit = true;
	  cin.get();
	  return;
	}

      while (column != '0' && column != '1' && column != '2')
	{
	  cout << "Column: ";
	  cin >> column;
	  cin.get();
	}
      
      if (board[row - 97][column - 48] == '-')
	{
	  query = false;
	}
      else
	{
	  cout << endl << "That location is taken." << endl;
	  row = ' ';
	  column = ' ';
	}
    }

  if (turn == 0)
    {
      board[row - 97][column - 48] = 'x';
    }
  else
    {
      board[row - 97][column - 48] = 'o';
    }
  
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

bool checkTie(char board[][3])
{
  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
	{
	  if (board[i][j] == '-')
	    {
	      return false;
	    }
	}
    }
  return true;
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

