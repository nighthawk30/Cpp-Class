/*
Nathan Taylor
Node Class
*/

#include "Node.h"

//create node
Node::Node()
{
  data = NULL;
  next = NULL;//set to null bc other crap inside - possibly
}

Node::~Node()
{
  delete data;
}

//Data
Node::setStudent(Student* nstudent)
{
  data = nstudent;
}

Student* Node::getStudent()
{
  return data;
}

//Node
Node::setNext(Node* nnode)
{
  next = nnode;
}

Node* Node::getNext()
{
  return next;
}
