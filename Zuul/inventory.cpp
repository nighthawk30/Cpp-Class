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
//add an item to your inventory
inventory::addInventory(char* item)
{
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
