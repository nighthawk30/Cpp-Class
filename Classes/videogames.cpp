/*
Nathan Taylor
Video games class
 */
#include "videogames.h"

//constructor for videogame specific variables and parent
videogames::videogames (char* ntitle, int nyear, int ntype, int nrating, char* npublisher) : media (ntitle, nyear, ntype)
{
  rating = nrating;
  publisher = npublisher;
}
