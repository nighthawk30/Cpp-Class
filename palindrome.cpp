#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char input[80];
  char* censored = new char[80];
  int arrayindex = 0;

  cin.get(input, sizeof(input));
  cin.get();

  for (int i = 0; input[i] != '\0'; i++)
    {
      if (input[i] > 57)//the cut off point for ascii numbers
	{
	  censored[arrayindex] = input[i];
	  arrayindex++;
	}
    }

  censored[arrayindex] = '\0';
  censored
  
  cout << censored << endl;
  return 0;
}
