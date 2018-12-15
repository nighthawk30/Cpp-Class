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
  char* data;//Temp
public:
  //Temp
  void setData(char* ndata)
  {
    data = new char[strlen(ndata)];
    strcpy(data, ndata);
  }
  char* getData()
  {
    return  data;
  }
  //
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

Node* addLeaf(Node* root, int nindex, char* ndata);
void printTree(Node* root, int search);

int main()
{
  Node* start = NULL;
  start = addLeaf(start, 10, "1");
  start = addLeaf(start, 6, "2");
  start = addLeaf(start, 7, "3");
  start = addLeaf(start, 11, "4");
  start = addLeaf(start, 3, "5");
  start = addLeaf(start, 30, "6");
  start = addLeaf(start, 25, "7");
  start = addLeaf(start, 15, "8");
  start = addLeaf(start, 12, "9");
  printTree(start, 12);
  return 0;
}

void printTree(Node* root, int search)
{
  
  //if the current node is null - first
  if (root == NULL)
    {
      cout << "Empty" << endl;
    }
  else if (root -> getIndex() == search)
    {
      cout << root -> getData() << endl;
    }
  else if (root -> getIndex() > search)//to the left
    {
      if (root -> getLeft() != NULL)//recurse
	{
	  printTree(root -> getLeft(), search);
	}
      else//DNE
	{
	  cout << "Not Found" << endl;
	}
    }
  else//to the right
    {
      if (root -> getRight() != NULL)//recurse
	{
	  printTree(root -> getRight(), search);
	}
      else//DNE
	{
	  cout << "Not Found" << endl;
	}
    }
  return;
}

//recursive add function
Node* addLeaf(Node* root, int nindex, char* ndata)
{
  //if the current node is null - first
  if (root == NULL)
    {
      root = new Node;
      root -> setIndex(nindex);
      root -> setData(ndata);
    }
  else if (root -> getIndex() > nindex)//to the left
    {
      if (root -> getLeft() != NULL)//recurse
	{
	  addLeaf(root -> getLeft(), nindex, ndata);
	}
      else//position found
	{
	  Node* leaf = new Node;
	  leaf -> setIndex(nindex);
	  leaf -> setData(ndata);
	  root -> setLeft(leaf);
	}
    }
  else//to the right
    {
      if (root -> getRight() != NULL)//recurse
	{
	  addLeaf(root -> getRight(), nindex, ndata);
	}
      else//position found
	{
	  Node* leaf = new Node;
	  leaf -> setIndex(nindex);
	  leaf -> setData(ndata);
	  root -> setRight(leaf);
	}
    }
  return root;
}
