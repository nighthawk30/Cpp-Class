/*
Nathan Taylor
Header file for movies class
 */
//Header Guard for redef
#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include "media.h"

using namespace std;

class movies : public media
{
 public:
  //sub class constructor
  movies (char* ntitle, int nyear, int ntype, char* ndirector, int nduration, int nrating);
  char* director;
  int duration;
  int rating;
};

#endif
