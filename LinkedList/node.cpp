/*
Nathan Taylor
Node Class
*/

#include "node.h"

//create node
node::node()
{
  data = NULL;
  next = NULL;//set to null bc other crap inside - possibly
}

node::~node()
{
  delete data;
}

//Data
node::setData(student* nstudent)
{
  data = nstudent;
}

student* node::getData()
{
  return data;
}

//Node
node::setNext(node* nnode)
{
  next = nnode;
}

node* node::getNext()
{
  return next;
}
