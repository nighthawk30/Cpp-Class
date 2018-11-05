/*
Nathan Taylor
Header file for the music class
 */
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
  music (char* ntitle, int nyear, int ntype, int nduration, char* nartist, char* npublisher);
  int duration;
  char* artist;
  char* publisher;
};

#endif
