#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"
#include <cstdlib>

using namespace std;

void setup()
{
  cout << "\033[8m";
}

class Node{
 public:
  Node(Student* newvalue);
  ~Node();
  setup();
  Node* getNext();
  Student* getStudent();
  void setNext(Node* newnext);
private:
  Student* value;
  Node* next;
};

#endif
