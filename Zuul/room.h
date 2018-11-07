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
  room();

  //function init
  setDescription(char* ndescript);
  setMap(char* nkey1, char* nkey2, char* nkey3, char* nkey4, room* ndestin1, room* ndestin2, room* ndestin3, room* ndestin4);
  //room* exitToRoom(char* key);
  
  //variable init
  char* descript;  
  map<char*,room*> exits;

};
