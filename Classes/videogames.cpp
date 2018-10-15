#include "videogames.h"

videogames::videogames (char* ntitle, int nyear, int ntype, int rating, char* publisher) : media (ntitle, nyear, ntype)
{
  rating = nrating;
  publisher = npublisher;
}
