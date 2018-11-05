/*
Nathan Taylor
Movie Class
 */
#include "movies.h"

//constructor for movie class using movie specific information and parent variables
movies::movies (char* ntitle, int nyear, int ntype, char* ndirector, int nduration, int nrating) : media (ntitle, nyear, ntype)
{
  director = ndirector;
  duration = nduration;
  rating = nrating;
}
