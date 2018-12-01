/*
Nathan Taylor
11/28/18
Linked List Class
*/
#include "Node.h"
#include "Student.h"

Node* studentAdd(Node* start, Student* peer);
void printList(Node* start);
Node* studentDelete(Node* start, int idnum);

int main()
{
  //linked
  char* command = new char[80];
  bool quit = false;
  Node* start = NULL;
  
  cout << "Welcome to the student linkedlist" << endl << endl << "Commands:" << endl;
  cout << "'add' - Add a new student" << endl;
  cout << "'print' - Print out the list of students and their information" << endl;
  cout << "'delete' - Delete a student by their id number" << endl;
  cout << "'quit' - exit the program" << endl;
  
  while (!quit)
    {
      cout << endl << "Command: ";
      cin.getline(command, 80);
      
      if (strcmp(command, "add") == 0)
	{
	  char* first = new char[80];
	  char* last = new char[80];
	  char* id = new char[80];
	  char* grade = new char[80];

	  cout <<pri  "First Name: ";
	  cin.getline(first, 80);
	  cout << "Last Name: ";
	  cin.getline(last, 80);
	  cout << "ID Number: ";
	  cin.getline(id, 80);
	  cout << "GPA: ";
	  cin.getline(grade, 80);

	  Student* peer = new Student(first, last, atoi(id), atof(grade));	  
	  start = studentAdd(start, peer);
	  cout << endl << "Student Added" << endl;
	}
      else if (strcmp(command, "print") == 0)
	{
	  cout << endl;
	  printList(start);
	}
      else if (strcmp(command, "delete") == 0)
	{
	  cout << "Student ID: ";
	  cin.getline(command, 80);
	  start = studentDelete(start, atoi(command));
	}
      else if (strcmp(command, "quit") == 0)
	{
	  quit = true;
	}
      else
	{
	  cout << "Invalid Command" << endl;
	}
    }

  cout << endl << "Aborted (core dumped)\t\t\t-jk";

  return 0; 
}

Node* studentAdd(Node* start, Student* peer)
{
  if (start == NULL)//empty
    {
      start = new Node(peer);
      //return start;
    }
  else if (peer -> studentID < start -> getStudent() -> studentID)//it is before the first item in the list - only occurs the first time
    {
      Node* spark = new Node(peer);
      spark -> setNext(start);
      return spark;
    }
  else if (start -> getNext() != NULL)//last
    {
      //id between current node and next node
      if (peer -> studentID < start -> getNext() -> getStudent() -> studentID)
	{
	  Node* spark = new Node(peer);
	  spark -> setNext(start -> getNext());
	  start -> setNext(spark);
	  //return start;
	}
      else//shift search one recursion
	{
	  studentAdd(start -> getNext(), peer);
	}
    }
  else//last item in the list
    {
      Node* spark = new Node(peer);
      start -> setNext(spark);
      //return start;
    }
  
  return start;//always return start unless the peer is before the first item
}

void printList(Node* start)
{
  if (start == NULL)//empty list
    {
      cout << "List Empty" << endl;
    }
  else
    {
      Student* data = start -> getStudent();
      cout << data -> nameFirst << " " << data -> nameLast << ", " << data -> studentID << ", " << data -> gpa << endl;

      //if there is a next node
      if (start -> getNext() != NULL)
	{
	  printList(start -> getNext());
	}
    }
  
}

Node* studentDelete(Node* start, int idnum)
{
  if (start == NULL)
    {
      cout << endl << "List Empty" << endl;
    }
  else if (start -> getStudent() -> studentID == idnum)//first item in the list - only occurs the first time
    {
      Node* top = NULL;
      if (start -> getNext() != NULL)//not the only item in the list
	{
	  top = start -> getNext();
	}
      delete start;
      
      cout << endl << "Student Deleted" << endl;

      //either a new empty top or the next node
      return top;
    }
  else if (start -> getNext() != NULL)//Not Last
    {
      //if the node after the current one holds the correct id
      if (start -> getNext() -> getStudent() -> studentID == idnum)
	{
	  //if the node with the id is not the last node
	  if (start -> getNext() -> getNext() != NULL)
	    {
	      Node* temp = start -> getNext();
	      start -> setNext(temp -> getNext());
	      delete temp;
	      cout << endl << "Student Deleted" << endl;
	    }
	  else//the node that contains the id is the last node
	    {
	      delete (start -> getNext());
	      start -> setNext(NULL);
	      cout << endl << "Student Deleted" << endl;
	    }
	}
      else//was not found in this iteration
	{
	  studentDelete(start, idnum);
	}
    }
  else//last item in the list
    {
      cout << endl << "Student Not Found" << endl;
    }

  return start;
}
