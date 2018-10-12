#include "media.h"

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
