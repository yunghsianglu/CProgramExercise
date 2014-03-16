/* file: student3.c
   purpose: demonstrate how to write a program with 2 .c files
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student3.h"

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

