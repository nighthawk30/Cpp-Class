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

/*

//information held on the students
struct Student
{
  char nameFirst[10];
  char nameLast[10];
  int studentID;
  float GPA;
};

void studentAdd(vector <Student*>* list);
void listPrint(vector <Student*>* list);
void studentDelete(vector <Student*>* list);

int main()
{
  vector <Student*>* list = new vector <Student*>();
  int students = 0;
  char command = '-';
  //call function
  cout << "Welcome to the student database: Commands:" << endl;
  cout << "'add' - Add a new student" << endl;
  cout << "'print' - Print out the list of students and their information" << endl;
  cout << "'delete' - Delete a student by their id number" << endl;
  cout << "'quit' - exit the program" << endl;

  while (command != 'q')
    {
      if (command == 'a')
	{
	  cout << endl << "Add Function" << endl;
	  studentAdd(list);
	}
      else if (command == 'p')
	{
	  cout << endl << "Print Function" << endl;
	  listPrint(list);
	}
      else if (command == 'd')
	{
	  cout << endl << "Delete Function" << endl;
	  studentDelete(list);
	}
      
      command = '-';
      cout << endl << "Command: ";
      cin.get(command);
      while (cin.get() != '\n');
    }
    
  return 0;
}

//creates a new student and adds it to the vector
void studentAdd(vector <Student*>* list)
{
  char input[10];
  Student* initial = new Student;//use Student intial; to create a local student struct and Student* initial = new Student; to create a Global/pointer struct
  //vector -> student -> set
  cout << "First Name: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  strcpy(initial -> nameFirst, input);

  //Last Name
  cout << "Last Name: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  strcpy(initial -> nameLast, input);
  //cout << "Name: " << initial -> nameLast << endl;

  //ID #
  cout << "ID Number: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  int idnum = 0;
  for (int i = 0; i < strlen(input); i++)
    {
      idnum += (input[i] - 48) * pow(10,strlen(input) - i - 1);
    }
  initial -> studentID = idnum;
  //cout << "ID: " << initial -> studentID << endl;

  //GPA
  cout << "GPA: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  float gpa = 0;
  int power = strlen(input) - 1;
  int decimal = -1;
  for (int i = 0; i < strlen(input); i++)
    {
      if (input[i] == '.')
	{
	  decimal = i;
	  break;
	}
    }
  
  if (decimal != -1)
    {
      power = decimal - 1;
    }
  
  for (int i = 0; i < strlen(input); i++)
    {
      if (i != decimal)
	{
	  gpa += (input[i] - 48) * pow(10, power--);
	}
    }
  //cout << gpa << endl;
  initial -> GPA = gpa;
  
  //Add student to the vector
  list -> push_back(initial);
  
  return;
  //create student with given info + add it to vector of students
}

//print out all students in the database along with id and gpa
void listPrint(vector <Student*>* list)
{
  //get it out of vector for test
  vector <Student*>::iterator it;
  for (it = list -> begin(); it != list -> end(); it++)
    {
      cout << (*it) -> nameFirst << " " << (*it) -> nameLast << ": " << (*it) -> studentID << ", " << setprecision(2) << fixed << (*it) -> GPA << endl;
    }
  return;
}

//use student id to delete student
void studentDelete(vector <Student*>* list)
{
  char input[10];
  //ID #
  cout << "ID Number: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  int idnum = 0;
  for (int i = 0; i < strlen(input); i++)
    {
      idnum += (input[i] - 48) * pow(10,strlen(input) - i - 1);
    }
  
  //get it out of vector for test
  vector <Student*>::iterator it;
  for (it = list -> begin(); it != list -> end(); it++)
    {
      if ((*it) -> studentID == idnum)
	{
	  list -> erase(it);
	  delete *it;
	  cout << "Student Deleted" << endl;
	  break;
	}
    }
  
  return;
}

*/
