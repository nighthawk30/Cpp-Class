#include "Node.h"

Node::Node(Student* newvalue)
{
  value = newvalue;
  next = NULL;
}

Node::~Node()
{
  delete value;
}

Node* Node::getNext()
{
  return next;
}

Student* Node::getStudent()
{
  return value;
}

void Node::setNext(Node* newnext)
{
  next = newnext;
  return;
}
