#include <iostream>

using namespace std;

class music//::media
{
 public:
  music (char *ntitle, int nyear, int nduration, char* nartist, char* npublisher);
  char* title;
  int year;
  int duration;
  char* artist;
  char* publisher;
};
