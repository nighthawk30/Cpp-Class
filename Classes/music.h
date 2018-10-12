//Header Guard for redefinition
#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include "media.h"

using namespace std;

class music : public media
{
 public:
  //sub class constructor
  music (char *ntitle, int nyear, int nduration, char* nartist, char* npublisher, int ntype);
  int duration;
  char* artist;
  char* publisher;
};

#endif
