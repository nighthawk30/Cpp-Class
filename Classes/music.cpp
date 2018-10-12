#include "music.h"

music::music (char* ntitle, int nyear, int nduration, char* nartist, char* npublisher, int ntype) : media (ntitle, nyear, ntype)
{
  duration = nduration;
  artist = nartist;
  publisher = npublisher;
}
