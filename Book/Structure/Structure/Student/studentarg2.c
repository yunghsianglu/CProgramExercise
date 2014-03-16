/* file: studentarg2.c
   purpose: demonstrate that object attributes are copied to
   argument
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LENGTH 50
typedef struct
{
  char name[NAME_LENGTH];
  int year;
  float GPA;
} Student;

void printStudent(Student s)
{
  printf("The student's name is %s.\n", s.name);
  switch (s.year)
    {
    case 1:
      printf("   first-year.\n");
      break;
    case 2:
      printf("   sophomore.\n");
      break;
    case 3:
      printf("   junior.\n");
      break;
    case 4:
      printf("   senior.\n");
      break;
    }
  printf("   GPA = %4.2f.\n", s.GPA);
}


void changeStudent(Student s)
{
  printStudent(s);
  strcpy(s.name, "Jennifer Jones");
  s.year = 4;
  s.GPA = 3.3;
  printStudent(s);
}

int main(int argc, char * argv[])
{
  Student s1;
  strcpy(s1.name, "Amy Smith");
  s1.year = 3;
  s1.GPA = 3.6;
  changeStudent(s1);
  printf("===main===\n");
  printStudent(s1);
  return EXIT_SUCCESS;
}
