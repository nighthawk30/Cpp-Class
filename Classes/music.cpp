/*
Nathan Taylor
music class
 */
#include "music.h"

//initializes music specific information and includes parent data
music::music (char* ntitle, int nyear, int ntype, int nduration, char* nartist, char* npublisher) : media (ntitle, nyear, ntype)
{
  duration = nduration;
  artist = nartist;
  publisher = npublisher;
}
