#include <iostream>
#include "media.h"

using namespace std;

int main()
{
  media* thing = new media();
  thing -> printStuff();
  cout << "I don't know what I am doing";
  return 0;
}
