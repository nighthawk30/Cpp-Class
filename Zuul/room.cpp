/*
Nathan Taylor
Room Class
 */

#include "room.h"

room::room(){};

room::setDescription(char* ndescript)
{
  ndescript = new char[strlen(ndescript)];
  strcpy(descript, ndescript);
}

room::setMap(char* nkey1, char* nkey2, char* nkey3, char* nkey4, room* ndestin1, room* ndestin2, room* ndestin3, room* ndestin4)
{
  exits[nkey1] = ndestin1;
  exits[nkey2] = ndestin2;
  exits[nkey3] = ndestin3;
  exits[nkey4] = ndestin4;
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
