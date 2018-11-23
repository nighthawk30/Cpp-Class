/*
Nathan Taylor
Header file for room class
 */

#include <iterator>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class room
{
 public:

  //class init
  room(char* ndescript);

  //function init
  setDescription(char* ndescript);
  addStorage(char* item);
  findStorage(char* item);
  setExits(room* ndestin1, room* ndestin2, room* ndestin3, room* ndestin4, room* ndestin5, room* ndestin6);
  
  //variable init
  vector <char*>* storage;
  vector <char*>::iterator it;
  char* descript;
  room** exits;

};
