/*
Nathan Taylor
Header file for student class
*/
//Header guard for redef
#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>

class Student
{
 public:
  //class init
  Student(char* nnameFirst, char* nnameLast, int nstudentID, float ngpa);

  //destructor
  //~Student();
  
  //var init
  char* nameFirst;
  char* nameLast;
  int studentID;
  float gpa;
};

#endif
