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

void input(char* command);

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

  //ROOM SETUP
  //creates space on the fly for the string constant that you cannot access  
  room* r0 = new room("heyo");
  room* r1 = new room("hi");//can also r# -> setDescription("");

  //ROOM MAP SETUP
  r0 -> setExits(r1, NULL, r1, NULL, NULL, NULL);
  r1 -> setExits(r0, NULL, NULL, r0, NULL, NULL);


  /*
  char input[80];
  cout << endl << "Direction: ";
  cin.getline(input, 80);
*/

  input(command);
  cout << command;
  input(command);
  cout << command;


  return 0;
}

void input(char* command)
{
  cout << endl << "Command: ";
  cin.getline(command, 80);
  return;
}
