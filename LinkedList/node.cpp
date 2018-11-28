/*
Nathan Taylor
Node Class
*/

#include "node.h"

//create node
node::node()
{
  data = new student*();
  next = new node*();
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
