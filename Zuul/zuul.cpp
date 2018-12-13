/*
Nathan Taylor
10/24/18
Text Based Maze with Items
 */

#include <cmath>
#include "room.h"
#include "inventory.h"

using namespace std;

void input(char* command, bool &quit, room* &current, inventory* pack);
void goToCommand(char* direction, room* &current);
void getInventory(inventory* pack);
void dropItemCommand(char* item, room* current, inventory* pack);
void pickupItemCommand(char* item, room* current, inventory* pack);
void roomCommand(room* current);
void helpCommand();

int main()
{
  //cin.ignore(); if switching between cin << and get line
  cout << "Entry Statement" << endl << endl << "Commands:" << endl;
  helpCommand();
  
  //ROOM SETUP
  //creates space on the fly for the string constant that you cannot access  
  room* r0 = new room("Room 0");
  room* r1 = new room("Room 1");//can also r# -> setDescription("");
  room* r2 = new room("Room 2");
  room* r3 = new room("Room 3");
  room* r4 = new room("Room 4");
  room* r5 = new room("Room 5");
  room* r6 = new room("Room 6");
  room* r7 = new room("Room 7");
  room* r8 = new room("Room 8");
  room* r9 = new room("Room 9");
  room* r10 = new room("Room 10");
  room* r11 = new room("Room 11");
  room* r12 = new room("Room 12");
  room* r13 = new room("Room 13");
  room* r14 = new room("Room 14");
  room* r15 = new room("Room 15");

  //ROOM Exit SETUP
  r0 -> setExits(r1,r3,r5,r7,r9,NULL);
  r1 -> setExits(NULL,r2,r0,r8,NULL,NULL);
  r2 -> setExits(NULL,NULL,r3,r2,NULL,NULL);
  r3 -> setExits(r2,NULL,r4,r0,NULL,NULL);
  r4 -> setExits(r3,NULL,NULL,r5,NULL,NULL);
  r5 -> setExits(r0,r4,NULL,r6,NULL,NULL);
  r6 -> setExits(r7,r5,NULL,NULL,NULL,NULL);
  r7 -> setExits(r8,r0,r6,NULL,NULL,NULL);
  r8 -> setExits(NULL,r1,r7,NULL,NULL,NULL);
  r9 -> setExits(r10,NULL,NULL,NULL,NULL,r0);
  r10 -> setExits(r11,NULL,r9,NULL,NULL,NULL);
  r11 -> setExits(r12,NULL,r10,NULL,NULL,NULL);
  r12 -> setExits(r13,NULL,r11,NULL,NULL,NULL);
  r13 -> setExits(r14,NULL,r12,NULL,NULL,NULL);
  r14 -> setExits(r15,NULL,r13,NULL,NULL,NULL);
  r15 -> setExits(r0,NULL,r14,NULL,NULL,NULL);  

  //Set up items in rooms
  r0 -> addStorage("axe");
  r0 -> addStorage("spoon");

  //Inventory
  inventory* pack = new inventory();
  pack -> addInventory("wrench");
  pack -> addInventory("pencil");
  pack -> addInventory("map");
  
  //Initialization of variables
  int size = 4;
  bool quit = false;
  char* command = new char[80];
  room* current = r0;

  //RUN LOOP
  while (!quit)
    {
      input(command, quit, current, pack);
      if (current == r8)
	{
	  cout << "You Won! This is a lame game!" << endl;
	  break;
	}
    }
  cout << endl << "Aborted (core dumped)\t\t\t\t-jk" << endl;

  return 0;
}

//System for getting user input and splitting it into commands
void input(char* command, bool &quit, room* &current, inventory* pack)
{
  cout << endl << "Command: ";
  cin.getline(command, 80);
  int space = -1;
  //split into multiple words
  for (int i = 0; i < strlen(command); i++)
    {
      if (command[i] == ' ')
	{
	  space = i;
	}
    }

  if (space == -1)//one word
    {
      //Pathways
      if (strcmp(command,"quit") == 0)
	{
	  quit = true;
	  cout << "Quitter - Lame." << endl;
	}
      else if (strcmp(command, "inventory") == 0)
	{
	  getInventory(pack);
	}
      else if (strcmp(command, "room") == 0)
	{
	  roomCommand(current);
	}
      else if (strcmp(command, "help") == 0)
	{
	  helpCommand();
	}
      else if (strcmp(command, "hell") == 0)
	{
	  cout << "WOOOOOOAAAH-OOHH WE'RE HALF WAY THERE-ER OOOOH-OOOOOOOOH LIIIVING ON A PRAAAAYER-ER" << endl << "NEVA GUNNA GIVE U UP, NEVA GUNNA LET U DOWN, NEVA GUNNA RUN AROUND OR DESERT U." << endl << "BAAAKE ME UP!! BAKE ME UP A PIE! 1/4 CUPS!! OF FLOUR FOR OUR PIE (SAAAVE ME!!) SET THE TEMP AND SAVE ME FROM THE PIE!!  -  curtesy of Aidan Derocher" << endl;
	}
      else
	{
	  cout << "Invalid Command" << endl;
	  cout << "|" << command << "|" << endl;
	}
    }
  else//two word
    {
      char* action = new char[space+1];//what you are doing
      char* call = new char[strlen(command) - space];//action subject

      //splitter
      for (int i = 0; i < strlen(command); i++)
	{
	  if (i < space)
	    {
	      action[i] = command[i];
	    }
	  if (i > space)
	    {
	      call[i-space - 1] = command[i];
	    }
	}
      //cout << "Space|" << space << "|" << endl << "Len|" << strlen(command) << "|" << endl;
      action[space] = '\0';//add in endline character
      call[strlen(command) - space - 1] = '\0';
      
      //cout << "|" << action << "|" << call << "|" << endl;
      //Pathways
      if (strcmp(action, "go") == 0)
	{
	  goToCommand(call, current);
	}
      else if (strcmp(action, "pickup") == 0)
	{
	  pickupItemCommand(call, current, pack);
	}
      else if (strcmp(action, "drop") == 0)
	{
	  dropItemCommand(call, current, pack);
	}
      else
	{
	  cout << "Invalid Command" << endl;
	}
      delete action;
      delete call;
    }
  
  return;
}

void helpCommand()
{
  cout << "'go' (direction) - Move in one of the cardinal directions" << endl;
  cout << "'drop (item)' - Leave an item from your backpack in the room" << endl;
  cout << "'pickup (item)' - Put an item from the room into your backpack" << endl;
  cout << "'inventory' - List the contents of your backpack" << endl;
  cout << "'room' - Give the room description and items it contains" << endl;
  cout << "'help' - List the commands available" << endl;
  cout << "'quit' - Exit Game" << endl;
  return;
}

//take an item out of a room and put it in your inventory
void pickupItemCommand(char* item, room* current, inventory* pack)
{
  if (current -> findStorage(item))
    {
      vector <char*>* crate = current -> storage;
      vector <char*>::iterator it;
      for (it = crate -> begin(); it != crate -> end(); it++)
	{
	  if (strcmp(*it, item) == 0)
	    {
	      crate -> erase(it);
	      //delete *it;
	      break;
	    }
	}
      pack -> addInventory(item);
    }
  else
    {
      cout << "Item Not Found" << endl;
    }
  return;
}

void dropItemCommand(char* item, room* current, inventory* pack)
{
  if (pack -> findInventory(item))
    {
      vector <char*>* crate = pack -> backpack;
      vector <char*>::iterator it;
      for (it = crate -> begin(); it != crate -> end(); it++)
	{
	  if (strcmp(*it, item) == 0)
	    {
	      crate -> erase(it);
	      //delete *it;
	      break;
	    }
	}
      current -> addStorage(item);
    }
  else
    {
      cout << "Item Not Found" << endl;
    }
  return;
}

//print contents of inventory
void getInventory(inventory* pack)
{
  bool empty = true;
  cout << "Inventory:";
  vector <char*>* crate = pack -> backpack;
  vector <char*>::iterator it;
  for (it = crate -> begin(); it != crate -> end(); it++)
    {
      empty = false;
      cout << " " << *it;
    }
  if (!empty)
    {
      cout << endl;
    }
  return;
}

//move to the indicated room
void goToCommand(char* direction, room* &current)
{
  int dir = -1;
  if (strcmp(direction, "north") == 0 ||
      strcmp(direction, "North") == 0)
    {
      //test if room exists
      if (current -> exits[0] != NULL)
	{
	  dir = 0;
	}
      else
	{
	  cout << "Direction Unavailabe" << endl;
	}
    }
  else if (strcmp(direction, "east") == 0 ||
      strcmp(direction, "East") == 0)
    {
      if (current -> exits[1] != NULL)
	{
	  dir = 1;
	}
      else
	{
	  cout << "Direction Unavailable" << endl;
	}
    }
  else if (strcmp(direction, "south") == 0 ||
      strcmp(direction, "South") == 0)
    {
      if (current -> exits[2] != NULL)
	{
	  dir = 2;
	}
      else
	{
	  cout << "Direction Unavailabe" << endl;
	}
    }
  else if (strcmp(direction, "west") == 0 ||
      strcmp(direction, "West") == 0)
    {
      if (current -> exits[3] != NULL)
	{
	  dir = 3;
	}
      else
	{
	  cout << "Direction Unavailabe" << endl;
	}
    }
  else if (strcmp(direction, "down") == 0 ||
      strcmp(direction, "Down") == 0)
    {
      if (current -> exits[5] != NULL)
	{
	  dir = 5;
	}
      else
	{
	  cout << "Direction Unavailabe" << endl;
	}
    }
  else if (strcmp(direction, "up") == 0 ||
      strcmp(direction, "Up") == 0)
    {
      if (current -> exits[4] != NULL)
	{
	  dir = 4;
	}
      else
	{
	  cout << "Direction Unavailabe" << endl;
	}
    }
  else
    {
      cout << "Invalid Direction" << endl;
    }

  if (dir != -1)
    {
      //Movequit
      current = current -> exits[dir];
      //Enter Room Description
      roomCommand(current);
    } 
  return;
}

//print the contents of the room
void roomCommand(room* current)
{
  cout << current -> descript << endl;
  cout << "Exits: ";
  for (int i = 0; i < 6; i++)
    {
      if (current -> exits[i] != NULL)
	{
	  switch(i)
	    {
	    case 0:
	      cout << "north ";
	      break;
	    case 1:
	      cout << "east ";
	      break;
	    case 2:
	      cout << "south ";
	      break;
	    case 3:
	      cout << "west ";
	      break;
	    case 4:
	      cout << "up ";
	      break;
	    case 5:
	      cout << "down ";
	      break;
	    }
	}
    }
  cout << endl;
  vector <char*>* crate = current -> storage;
  vector <char*>::iterator it;
  cout << "Items:";
  for (it = crate -> begin(); it != crate -> end(); it++)
    {
      cout << " " << *it;
    }
  cout << endl;
  return;
}
