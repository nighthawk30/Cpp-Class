/*
Nathan Taylor
Header file for node
*/

#include <cstdlib>
#include <cstirng>

class stacknode
{
 public:
  stacknode(char* ndata);
  setRight(stackode* nright);
  setLeft(stacknode* nleft);
  setData(char* ndata);
  stacknode* getRight();
  stacknode* getLeft();
 private:
  stacknode* right;
  stacknode* left;
  char* data;
};
