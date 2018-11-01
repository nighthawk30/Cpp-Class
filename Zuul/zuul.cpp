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

using namespace std;

void input();

int main()
{
  char* command = new char[80];
  //cin.ignore(); if switching between cin << and get line
  cout << "Entry Statement" << endl << "Commands:" << endl << endl;
  cout << "'go' \"direction\" - Move in one of the cardinal directions" << endl;
  cout << "'inventory' - Print out your current inventory" << endl;
  //cout << "'open' - " << endl;
  cout << "'drop' - " << endl;
  cout << "'pickup' - " << endl;

  return 0;
}

void input()
{
  
  return;
}
