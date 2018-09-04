#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char input[80];
  char* censored = new char[80];
  int arrayindex = 0;
  bool palindrome = true;
  int strhalf = 0;
  
  cin.get(input, sizeof(input));
  cin.get();

  for (int i = 0; input[i] != '\0'; i++)
    {
      if (input[i] > 57)//the cut off point for ascii numbers
	{
	  censored[arrayindex] = tolower(input[i]);
	  arrayindex++;
	}
    }

  censored[arrayindex] = '\0';

  //cout << arrayindex << endl;
  //set where string half is - uses arrayindex for the length of censored
  if (arrayindex % 2 == 0)
    {
      strhalf = arrayindex / 2;
    }
  else
    {
      strhalf = (arrayindex - 1) / 2;
    }

  //cout << strhalf << endl;
  
  //Compare string sides character front to back
  for (int i = 0; i < strhalf; i++)
    {
      if (censored[i] != censored[arrayindex - i - 1])
	{
	  palindrome = false;
	}
    }
  
  if (palindrome)
    {
      cout << "Palindrome" << endl;
    }
  else
    {
      cout << "Not a Palindrome" << endl;
    }
      
  return 0;
}
