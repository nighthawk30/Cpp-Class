#include "movies.h"

movies::movies (char* ntitle, int nyear, int ntype, char* ndirector, int nduration, int nrating) : media (ntitle, nyear, ntype)
{
  director = ndirector;
  duration = nduration;
  rating = nrating;
}
