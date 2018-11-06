/*
Nathan Taylor
Room Class
 */

#include "room.h"

room::room(room* nkey1, char* nkey2, char* nkey3, char* nkey4, int ndes1, int ndes2, int ndes3, int ndes4)
{
  exits[nkey1] = ndes1;
  exits[nkey2] = ndes2;
  exits[nkey3] = ndes3;
  exits[nkey4] = ndes4;
}

room::exitToRoom(char* key)
{
  map<char*,int>::iterator it;
  for (it = exits.begin(); it != exits.end(); ++it)
    {
      if (strcmp(it -> first, key) == 0)
	{
	  return it -> second;
	}
    }
}

room::exitsTest(char* key)
{
  
}
