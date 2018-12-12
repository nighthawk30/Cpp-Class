/*
Nathan Taylor
Class for node
 */
#include "stacknode.h"

stacknode::stacknode(char* ndata)
{
  data = new char[strlen(ndata)];
  strcpy(data, ndata);
  right = NULL;
  left = NULL;
}

stacknode::~stacknode()
{
  delete data;
}

stacknode* stacknode::getRight()
{
  return right;
}

stacknode* stacknode::getLeft()
{
  return left;
}

char* stacknode::getData()
{
  return data;
}

stacknode::setRight(stacknode* nright)
{
  right = nright;
}

stacknode::setLeft(stacknode* nleft)
{
  left = nleft;
}

stacknode::setData(char* ndata)
{
  delete data;
  data = new char[strlen(ndata)];
  strcpy(data, ndata);
}
  
