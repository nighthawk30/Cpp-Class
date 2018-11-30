/*
Nathan Taylor
Student Class
*/

#include "student.h"

//create student
student::student(char* nnameFirst, char* nnameLast, int nstudentID, float ngpa)
{
  nameFirst = new char[strlen(nnameFirst)];
  strcpy(nameFirst, nnameFirst);
  nameLast = new char[strlen(nnameLast)];
  strcpy(nameLast, nnameLast);
  studentID = nstudentID;
  gpa = ngpa;
}

student::~student()
{
  delete nameFirst, nameLast;
}
