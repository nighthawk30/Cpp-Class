/*
Nathan Taylor
11/28/18
Linked List Class
*/
#include "node.h"
#include "student.h"

void studentAdd(node* start);
void printList(node* start);
void studentDelete(node* start);

int main()
{
  //linked
  char* command = new char[80];
  bool quit = false;
  node* start = new node();
  
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
	  studentAdd(start);
	}
      else if (strcmp(command, "print") == 0)
	{
	  printList(start);
	}
      else if (strcmp(command, "delete") == 0)
	{
	  studentDelete(start);
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

void studentAdd(node* start)
{
  node* spark = new node();
  //Standard process for walking through link
  node* last = start;
  while (last -> getNext() != NULL)
    {
      last = last -> getNext();
    }
  //Link last to new node
  last -> setNext(spark);
  
  //Put info into spark node
  char* firstname = new char[80];
  char* lastname = new char[80];
  char* id = new char[80];
  char* g = new char[80];

  cout << endl << "First Name: ";
  cin.getline(firstname, 80);

  cout << "Last Name: ";
  cin.getline(lastname, 80);

  cout << "ID Number: ";
  cin.getline(id, 80);

  cout << "GPA: ";
  cin.getline(g, 80);

  student* peer = new student(firstname, lastname, atoi(id), atof(g));

  spark -> setData(peer);

  cout << endl << "Student Added" << endl;
  
}

void printList(node* start)
{
  node* last = start;
  bool empty = true;
  
  while (last -> getNext() != NULL)
    {
      empty = false;
      last = last -> getNext();
      student* data = last -> getData();
      cout << endl << "First: " << data -> nameFirst << endl << "Last: " << data -> nameLast << endl;
      cout << "ID: " << data -> studentID << endl << "GPA: " << data -> gpa << endl;
    }
  
  if (empty)
    {
      cout << endl << "List Empty" << endl;
    }
}

void studentDelete(node* start)
{
  int stdid;
  bool found;
  cout << "Student ID: ";
  cin >> stdid;
  cin.ignore();

  node* previous;
  node* last = start;
  while (last -> getNext() != NULL)
    {
      previous = last;
      last = last -> getNext();
      if (last -> getData() -> studentID == stdid)
	{
	  previous -> setNext(last -> getNext());
	  delete last;
	  found = true;
	  cout << endl << "Student Deleted" << endl;
	  break;
	}
    }
  
  if (!found)
    {
      cout << endl << "Student Not Found" << endl;
    }
}
