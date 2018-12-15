/*
Nathan Taylor
Binary Search Tree and Visualizer
12/14/
*/

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
private:
  int index;
  Node* right = NULL;
  Node* left = NULL;
public:
  int getIndex()
  {
    return index;
  }
  Node* getRight()
  {
    return right;
  }
  Node* getLeft()
  {
    return left;
  }
  int setIndex(int nindex)
  {
    index = nindex;
  }
  void setRight(Node* nright)
  {
    right = nright;
  }
  void setLeft(Node* nleft)
  {
    left = nleft;
  }
};

Node* addLeaf(Node* root, int nindex);
void printTree(Node* root);

int main()
{
  Node* start = NULL;
  start = addLeaf(start, 10);
  start = addLeaf(start, 6);
  start = addLeaf(start, 7);
  start = addLeaf(start, 11);
  start = addLeaf(start, 3);
  start = addLeaf(start, 30);
  start = addLeaf(start, 35);
  start = addLeaf(start, 15);
  start = addLeaf(start, 12);
  printTree(start);
  return 0;
}

void printTree(Node* root)
{
  if (root != NULL)
    {
      cout << root -> getIndex() << endl;
    }

  if (root -> getLeft() != NULL)
    {
      cout << "/" << endl;
      printTree(root -> getLeft());
    }

  if (root -> getRight() != NULL)
    {
      cout << "\\" << endl;
      printTree(root -> getRight());
    }
  return;
}

//recursive add function
Node* addLeaf(Node* root, int nindex)
{
  //if the current node is null - first
  if (root == NULL)
    {
      root = new Node;
      root -> setIndex(nindex);
    }
  else if (root -> getIndex() > nindex)//to the left
    {
      if (root -> getLeft() != NULL)//recurse
	{
	  addLeaf(root -> getLeft(), nindex);
	}
      else//position found
	{
	  Node* leaf = new Node;
	  leaf -> setIndex(nindex);
	  root -> setLeft(leaf);
	}
    }
  else//to the right
    {
      if (root -> getRight() != NULL)//recurse
	{
	  addLeaf(root -> getRight(), nindex);
	}
      else//position found
	{
	  Node* leaf = new Node;
	  leaf -> setIndex(nindex);
	  root -> setRight(leaf);
	}
    }
  return root;
}
