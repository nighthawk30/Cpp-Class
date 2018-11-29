/*
Nathan Taylor
Header File for Node Class
HAVE FUN!
*/

#include <cstring>
#include <cstdlib>
#include <iostream>
#include "student.h"

using namespace std;

class node
{
 public:
  //class init
  node();

  //function init
  setData(student* nstudent);
  student* getData();
  setNext(node* nnode);
  node* getNext();

  //variable init
  node* next;
  student* data;
};
