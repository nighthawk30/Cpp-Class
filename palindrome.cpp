#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char input[80];
  char* censored = new char[80];
  int arrayindex = 0;
  bool palindrome = true;
  
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
  
  //Compare string sides character front to back
  for (int i = 0; censored[i] != '\0'; i++)
    {
      if (censored[i] != censored[sizeof(censored) - i - 2])
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
