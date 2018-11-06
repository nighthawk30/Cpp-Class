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
  room();
  setMap(char* nkey1, char* nkey2, char* nkey3, char* nkey4, room* ndes1, room* ndes2, room* ndes3, room* ndes4);
  int exitToRoom(char* key);
  map<char*,int> exits;
};
