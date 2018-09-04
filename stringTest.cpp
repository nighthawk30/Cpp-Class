#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char str[5];
  cin.get(str, 5) >> str;
  cin.get();
  
  cout << str << endl;
  return 0;
}
