#ifndef STUDENT2_H
#define STUDENT2_H
/* file: student2.h
   purpose: a programmer-defined type called Student
 */
#define NAME_LENGTH 50
typedef struct
{
  char name[NAME_LENGTH];
  int year;
  float GPA;
} Student;
#endif
