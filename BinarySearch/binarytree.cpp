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
void printCommands();

int main()
{
  Node* start = NULL;
  char* input = new char[80];
  cout << "\033[4mBinary Search Tree\033[0m" << endl << endl << "Commands:" << endl;
  printCommands();
  while(true)
    {
      cout << endl << "Command: ";
      cin.getline(input, 80);
      if (strcmp(input, "add") == 0)
	{
	  cout << "Index: ";
	  cin.getline(input, 80);
	  start = addLeaf(start, atoi(input));
	  cout << endl << "Node Added" << endl;
	}
      else if (strcmp(input, "print") == 0)
	{
	  cout << endl;
	  printTree(start);
	}
      else if (strcmp(input, "help") == 0)
	{
	  cout << endl;
	  printCommands();
	}
      else if (strcmp(input, "quit") == 0)
	{
	  break;
	}
      else
	{
	  cout << "Invalid Command" << endl;    
	}
    }
  cout << endl << "Aborted (core dumped)\t\t\t-jk";
  return 0;
}

void printCommands()
{
  cout << "'add' - Add a node to the tree" << endl;
  cout << "'delete' - Remove a node from the tree" << endl;
  cout << "'print' - Print out the tree structure" << endl;
  cout << "'help' - Print out the list of commands" << endl;
  cout << "'quit' - Exit the program" << endl;
}

void printTree(Node* root)
{
  if (root != NULL)
    {
      cout << root -> getIndex() << endl;
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
    }
  else
    {
      cout << "Tree Empty" << endl;
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
