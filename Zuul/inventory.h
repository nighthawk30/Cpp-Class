/*
Nathan Taylor
Header file for inventory class
*/

#include <iterator>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

class inventory
{
 public:
  //class init
  inventory();

  //function init
  addInventory(char* item);
  findInventory(char* item);

  //var init
  vector <char*>* backpack;
  vector <char*>::iterator it;
};
