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
  int size = 4;
  char* command = new char[80];
  /*
  int size = 4;
  room* current;
  char* commands[size];
  //commands
  char com1[5] = "West";
  char com2[5] = "East";
  char com3[6] = "South";
  char com4[6] = "North";
  //fill array
  strcpy(commands[0], com1);
  strcpy(commands[1], com2);
  strcpy(commands[2], com3);
  strcpy(commands[3], com4);
  */
  
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
  r1 -> setExits(r0, NULL, r0, NULL, NULL, NULL);

  room* current = r0;

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
  int space;
  //split into multiple words
  for (int i = 0; i < strlen(command); i++)
    {
      if (command[i] == ' ')
	{
	  space = i;
	}
    }

  char* action = new char[space+1];
  char* call = new char[strlen(command) - space];
  return;
}
