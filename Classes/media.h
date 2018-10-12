//Header Guard if statement for redefinition
#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>

using namespace std;

class media
{
 public:
  media (char *ntitle, int nyear, int type);
  int getType();
  char* title;
  int year;
  int type;
};

#endif
