/*
Nathan Taylor
Room Class
 */

#include "room.h"

room::room(char* ndescript)
{
  //the constant string degrades into a pointer
  descript = new char[strlen(ndescript)];//create space for the description
  strcpy(descript, ndescript);//copy the description into the room
};

room::setDescription(char* ndescript)
{
  delete descript;
  descript = new char[strlen(ndescript)];
  strcpy(descript, ndescript);
}

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
/*
room::exitToRoom(char* key)
{
  map<char*,room*>::iterator it;
  for (it = exits.begin(); it != exits.end(); ++it)
    {
      if (strcmp(it -> first, key) == 0)
	{
	  return it -> second;
	}
    }
}
*/

/*
room::exitsTest(char* key)
{
  
}
*/
