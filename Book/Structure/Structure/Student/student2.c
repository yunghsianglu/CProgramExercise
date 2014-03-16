/* file: student2.c
   purpose: include a programmer-defined header file
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student2.h"
int main(int argc, char * argv[])
{
  Student s1;
  strcpy(s1.name, "Amy Smith");
  s1.year = 3;
  s1.GPA = 3.6;
  printf("The student's name is %s.\n", s1.name);
  switch (s1.year)
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
  printf("   GPA = %4.2f.\n", s1.GPA);
  return EXIT_SUCCESS;
}
