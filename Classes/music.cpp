#include "music.h"

music::music (char* ntitle, int nyear, int ntype, int nduration, char* nartist, char* npublisher) : media (ntitle, nyear, ntype)
{
  duration = nduration;
  artist = nartist;
  publisher = npublisher;
}
