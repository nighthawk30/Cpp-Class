/*
Nathan Taylor
Student Class
*/

"student.h"

//create student
student::student(char* nnameFirst, char* nnameLast, int nstudentID, float ngpa)
{
  nameFirst = new char[strlen(nnameFirst)];
  strcpy(nameFirst, nnameFirst);
  nameLast = new char[strlen(nnameLast)];
  strcpy(nameFirst, nnameFirst);
  studentID = nstudentID;
  gpa = ngpa;
}
