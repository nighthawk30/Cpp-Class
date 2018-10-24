/*
Nathan Taylor
10/24/18
Text Based Maze with Items
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>
#include <cstdlib>
#include <cmath>
#include <windows.h>
#include <cwchar>

using namespace std;

void addSpace(int space);
void waitEnter();

int main()
{
  addSpace(100);
  cout << endl << "\t\t\t\t\tWELCOME TO ZUUL";
  cout << endl << "\t\t\t\t\t (Press Enter)";
  addSpace(25);
  char* command = new char[80];
  //cin << input;
  //cin.get(input);
  waitEnter();
  //cin.getline()?
  cout << "Command: ";
  cin.getline(command,80);
  addSpace(10);
  //cin.ignore(); if switching between cin << and get line


  
  return 0;
}

void addSpace(int space)
{
  for (int i = 0; i < space; i++)
    {
      cout << endl;
    }
  return;
}

void waitEnter()
{
  char* enter = new char[80];
  cin.getline(enter, 80);
  delete enter;
  return;
}
