/*
Nathan Taylor
Room Class
 */

#include "room.h"
//create room
room::room(char* ndescript)
{
  //the constant string degrades into a pointer
  descript = new char[strlen(ndescript)];//create space for the description
  strcpy(descript, ndescript);//copy the description into the room
  storage = new vector <char*>();//set up storage
}

room::addStorage(char* nitem)
{
  char* item = new char[strlen(nitem)+1];
  strcpy(item, nitem);
  item[strlen(nitem)] = '\0';
  storage -> push_back(item);
}
/*
//add an item to the room
room::addStorage(char* item)
{
  storage -> push_back(item);
  }*/
//test if an item exists in the room
int room::findStorage(char* item)
{
  bool found = false;
  for (it = storage -> begin(); it != storage -> end(); it++)
    {
      if (strcmp(*it, item) == 0)
	{
	  found = true;
	}
    }
  return found;
}
//set the room description
room::setDescription(char* ndescript)
{
  delete descript;
  descript = new char[strlen(ndescript)];
  strcpy(descript, ndescript);
}
//set the rooms exits
room::setExits(room* ndestin1, room* ndestin2, room* ndestin3, room* ndestin4, room* ndestin5, room* ndestin6)
{
  exits = new room* [6];
  exits[0] = ndestin1;//NORTH
  exits[1] = ndestin2;//EAST
  exits[2] = ndestin3;//SOUTH
  exits[3] = ndestin4;//WEST
  exits[4] = ndestin5;//UP
  exits[5] = ndestin6;//DOWN
}
