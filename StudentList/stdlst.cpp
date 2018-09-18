/*
Nathan Taylor
9/18/2018
Student info database
 */
#include <iostream>

using namespace std;

void studentAdd();
void listPrint();
void studentDelete();

//information held on the students
struct Student
{
  char nameFirst[10];
  char nameLast[10];
  int studentID;
  float GPA;
};

int main()
{
  //vector <Student*>* list;
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
	}
      else if (command == 'p')
	{
	  cout << endl << "Print Function" << endl;
	}
      else if (command == 'd')
	{
	  cout << endl << "Delete Function" << endl;
	}
 
      cout << "Command: ";
      command = cin.get();
      cin.clear();
    }

    
  return 0;
}

void studentAdd()
{
  //vector -> student -> set
  return;
  //create student with given info + add it to vector of students
}

//print out all students in the database along with id and gpa
void listPrint()
{
  return;
}

//use student id to delete student
void studentDelete()
{
  return;
}
