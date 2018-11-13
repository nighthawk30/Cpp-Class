/*
Nathan Taylor
Header file for room class
 */

#include <map>
#include <iterator>
#include <cstring>

using namespace std;

class room
{
 public:

  //class init
  room(char* ndescript);

  //function init
  setDescription(char* ndescript);
  setExits(room* ndestin1, room* ndestin2, room* ndestin3, room* ndestin4, room* ndestin5, room* ndestin6);
  //room* exitToRoom(char* key);
  
  //variable init
  char* descript;
  room** exits;
  //map<char*,room*> exits;

};
