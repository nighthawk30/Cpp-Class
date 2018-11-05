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
  room (char* nkey1, char* nkey2, int ndes1, int ndes2);
  int getDes(char* key);
  map<char*,int> exits;
};
