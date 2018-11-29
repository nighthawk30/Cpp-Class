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
  
  cout << "Welcome to the student linkedlist" << endl << "Commands:" << endl;
  cout << "'add' - Add a new student" << endl;
  cout << "'print' - Print out the list of students and their information" << endl;
  cout << "'delete' - Delete a student by their id number" << endl;
  cout << "'quit' - exit the program" << endl;
  
  while (!quit)
    {
      cout << "Command: ";
      cin.getline(command, 80);
      if (strcmp(command, "add"))
	{
	  studentAdd(start);
	}
      else if (strcmp(command, "print"))
	{

	}
      else if (strcmp(command, "delete"))
	{
	  
	}
      else if (strcmp(command, "quit"))
	{
	  quit = true;
	}
      else
	{
	  cout << "Invalid Command" << endl;
	}
    }
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
  cout << peer -> nameFirst << endl;
  cout << peer -> nameLast << endl;
  cout << peer -> studentID << endl;
  cout << peer -> gpa << endl;

  spark -> setData(peer);
}

void printList(node* start)
{

}

void studentDelete(node* start)
{

}
