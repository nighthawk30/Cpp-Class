/*
Nathan Taylor
Header file for student class
*/
//Header guard for redef
#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>

class student
{
 public:
  //class init
  student(char* nnameFirst, char* nnameLast, int nstudentID, float ngpa);

  //var init
  char* nameFirst;
  char* nameLast;
  int studentID;
  float gpa;
};

#endif
