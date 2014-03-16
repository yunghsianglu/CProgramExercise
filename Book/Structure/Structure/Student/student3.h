/* file: student3.h
 */
#ifndef STUDENT3_H
#define STUDENT3_H
#define NAME_LENGTH 50
typedef struct
{
  char name[NAME_LENGTH];
  int year;
  float GPA;
} Student;
void printStudent(Student s);
#endif
