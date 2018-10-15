//Header Guard for redef
#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H

#include <iostream>
#include "media.h"

using namespace std;

class videogames : public media
{
 public:
  //sub class for constructor
  videogames (char *ntitle, int nyear, int ntype, int rating, char* npublisher);
  int rating;
  char* publisher;
};

#endif
