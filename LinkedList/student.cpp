/*
Nathan Taylor
Student Class
*/

#include "Student.h"

//create student
Student::Student(char* nnameFirst, char* nnameLast, int nstudentID, float ngpa)
{
  nameFirst = new char[strlen(nnameFirst)];
  strcpy(nameFirst, nnameFirst);
  nameLast = new char[strlen(nnameLast)];
  strcpy(nameLast, nnameLast);
  studentID = nstudentID;
  gpa = ngpa;
}

Student::~Student()
{
  delete nameFirst, nameLast;
}
