/*
Nathan Taylor
10/24/18
Text Based Maze with Items
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "room.h"

using namespace std;

void input();

int main()
{
  char* command = new char[80];
  //cin.ignore(); if switching between cin << and get line
  cout << "Entry Statement" << endl << endl << "Commands:" << endl;
  cout << "'go' \"direction\" - Move in one of the cardinal directions" << endl;
  cout << "'inventory' - List the contents of your backpack" << endl;
  //cout << "'open' - " << endl;
  cout << "'drop (item)' - Leave an item from your backpack in the room" << endl;
  cout << "'pickup (item)' - Take an item from the current room and put it in your backpack" << endl;

  /*
  char* one = new char;
  *one = 'a';
  
  char* two = new char;
  *two = 'l';
  */
  
  room* r0 = new room();
  room* r1 = new room();
  room* r2 = new room();
  room* r3 = new room();
  room* r5 = new room();

  r0 -> setDescription("Heyo");

  /*
  char input[80];
  cout << endl << "Direction: ";
  cin.getline(input, 80);
  */
  cout << endl << "Description: " << r0 -> descript;
  return 0;
}

void input()
{
  return;
}
