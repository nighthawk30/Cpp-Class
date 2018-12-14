/*
Nathan Taylor
Inventory Class
*/

#include "inventory.h"
//create inventory
inventory::inventory()
{
  backpack = new vector <char*>();
}
/*
inventory::addInventory(char* item)
{
  backpack -> push_back(item);
}
*/
//add an item to your inventory
inventory::addInventory(char* nitem)
{
  char* item = new char[strlen(nitem)+1];
  strcpy(item, nitem);
  item[strlen(nitem)] = '\0';
  backpack -> push_back(item);
}
//test if an item is in your inventory
int inventory::findInventory(char* item)
{
  bool found = false;
  for (it = backpack -> begin(); it != backpack -> end(); it++)
    {
      if (strcmp(*it, item) == 0)
	{
	  found = true;
	}
    }
  return found;
}
