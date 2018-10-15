#include "videogames.h"

videogames::videogames (char* ntitle, int nyear, int ntype, int nrating, char* npublisher) : media (ntitle, nyear, ntype)
{
  rating = nrating;
  publisher = npublisher;
}
