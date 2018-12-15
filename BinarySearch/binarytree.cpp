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

Node* insertNode(Node* root, int nindex);
void printTree(Node* root, int level, int direction);//0 - left; 1 - none; 2 - Right
void printCommands();
Node* findNode(Node* root, int index);
Node* deleteNode(Node* strip, int index);

int main()
{
  Node* start = NULL;
  char* input = new char[80];
  cout << endl << "\033[4mBinary Search Tree\033[0m" << endl << "Commands:" << endl;
  printCommands();
  while(true)
    {
      cout << endl << "Command: ";
      cin.getline(input, 80);
      if (strcmp(input, "add") == 0)
	{
	  cout << "Index: ";
	  cin.getline(input, 80);
	  start = insertNode(start, atoi(input));
	  cout << endl << "Node Added" << endl;
	}
      else if (strcmp(input, "print") == 0)
	{
	  cout << endl;
	  printTree(start, -1, 1);
	}
      else if (strcmp(input, "help") == 0)
	{
	  cout << endl;
	  printCommands();
	}
      else if (strcmp(input, "delete") == 0)
	{
	  cout << "Index: ";
	  cin.getline(input, 80);
	  start = deleteNode(start, atoi(input));
	  //cout << endl << "Node Deleted" << endl;
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

Node* findNode(Node* root, int index)
{
  if (root != NULL)
    {
      //is current
      if (root -> getIndex() == index)
	{
	  return root;
	}
      else
	{
	  //test right
	  if (root -> getRight() != NULL)
	    {
	      root = findNode(root -> getRight(), index);
	    }
	  //test left
	  if (root -> getLeft() != NULL)
	    {
	      root = findNode(root -> getLeft(), index);
	    }
	  
	  if (root -> getIndex() == index)
	    {
	      return root;
	    }
	}
    }
  else
    {
      cout << endl << "Tree Empty" << endl;
    }
  
  return root;
}

Node* deleteNode(Node* root, int index)
{
  Node* strip = findNode(root, index);
  if (strip != NULL)
    {
      cout << strip -> getIndex() << endl;
    }
  return root;
}

void printCommands()
{
  cout << "'add' - Add a node to the tree" << endl;
  cout << "'delete' - Remove a node from the tree" << endl;
  cout << "'print' - Print out the tree structure" << endl;
  cout << "'help' - Print out the list of commands" << endl;
  cout << "'quit' - Exit the program" << endl;
}

void printTree(Node* root, int level, int direction)
{
  //cout << level << endl;
  if (root != NULL)
    {
      if (root -> getRight() != NULL)
	{ 
	  printTree(root -> getRight(), level + 1, 0);
	}

      //branch direction
      if (direction == 0)//more than first and to the left
	{
	  for (int i = 0; i < level; i++)
	    {
	      cout << "   ";
	    }
	  cout << " / ";
	}
      else if (direction == 2)//more than first and to the right
	{
	  for (int i = 0; i < level; i++)
	    {
	      cout << "   ";
	    }
	  cout << " \\ ";
	}
      
      //print
      cout << root -> getIndex() << endl;

      if (root -> getLeft() != NULL)
	{
	  printTree(root -> getLeft(), level + 1, 2);
	}
    }
  else
    {
      cout << "Tree Empty" << endl;
    }
  return;
}

//recursive add function
Node* insertNode(Node* root, int nindex)
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
	  insertNode(root -> getLeft(), nindex);
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
	  insertNode(root -> getRight(), nindex);
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
