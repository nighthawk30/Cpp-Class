/*
Nathan Taylor
Parent Class
 */
#include "media.h"
//initialize parent variables that all media contain
media::media(char* ntitle, int nyear, int ntype)
{
  title = ntitle;
  year = nyear;
  type = ntype;
}
		      
int media::getType()
{
  return type;
}
