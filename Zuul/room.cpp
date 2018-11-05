/*
Nathan Taylor
Room Class
 */

#include "room.h"

room::room(char* nkey1, char* nkey2, int ndes1, int ndes2)
{
  exits[nkey1] = ndes1;
  exits[nkey2] = ndes2;
}

room::getDes(char* key)
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
