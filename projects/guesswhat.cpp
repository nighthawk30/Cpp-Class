/*
Nathan Taylor
8/28/2018
C++ Guessing Game
*/

#include <iostream>

using namespace std;

int main()
{
  bool playagain = true;
  char playInput = ' ';
  while (playagain)
    {
      playagain = false;
      cout << endl;
      cout << "---------------------------" << endl;
      cout << "  This is a guessing game  " << endl;
      cout << "---------------------------" << endl;
      int randint = 0;
      int input = 0;
      int guesses = 0;
      bool correct = false;
      //cout << srand(time(NULL)) << endl;
      while (!correct)
	{
	  input = 0;
	  cout << endl;
	  cout << "Guess a number: ";
	  cin >> input;

	  if (input > randint)
	    {
	      cout << "Too High" << endl;
	      guesses++;
	    }
	  else if (input < randint)
	    {
	      cout << "Too Low" << endl;
	      guesses++;
	    }
	  else
	    {
	      cout << "You guessed it!" << endl;
	      guesses++;
	      if (guesses > 1)
		{
		  cout << "You needed " << guesses << " guesses" << endl;
		}
	      else
		{
		  cout << "You needed 1 guess" << endl;
		}
	      correct = true;
	    }
	}
      cout << endl;
      cout << "Do you want to play again? (y/n): ";
      cin >> playInput;
      if (playInput == 'y')
	{
	  playagain = true;
	}
    }
}
