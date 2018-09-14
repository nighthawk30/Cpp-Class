/*
Nathan Taylor
8/28/2018
C++ Guessing Game
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  bool playagain = true;
  char playInput = ' ';
  //main play loop
  while (playagain)
    {
      playagain = false;//game start
      cout << endl;
      cout << "---------------------------" << endl;
      cout << "  This is a guessing game  " << endl;
      cout << "---------------------------" << endl;
      srand(time(NULL));
      //float rnd =  rand();
      //cout << rnd << endl;
      int randint =  100 * (rand() / float(RAND_MAX));//creates a random number
      int input = 0;
      int guesses = 0;
      bool correct = false;
      //guessing loop
      while (!correct)
	{
	  input = 0;
	  cout << endl;
	  cout << "Guess a number: ";
	  cin >> input;
	  //game logic
	  if (input - randint > .1)
	    {
	      cout << "Too High" << endl;
	      guesses++;
	    }
	  else if (input - randint < -.1)
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
      //replay logic
      cout << endl;
      cout << "Do you want to play again? (y/n): ";
      cin >> playInput;
      if (playInput == 'y')
	{
	  playagain = true;
	}
    }
}
