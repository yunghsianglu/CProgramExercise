/* file: studentmalloc.c
   purpose: create a Student object using malloc
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

int main(int argc, char * argv[])
{
  Student * s;
  s = malloc(sizeof(Student));
  strcpy(s -> name, "Amy Smith");
  s -> year = 3;
  s -> GPA = 3.6;
  printf("The student's name is %s.\n", s -> name);
  switch (s -> year)
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
  printf("   GPA = %4.2f.\n", s -> GPA);
  free (s);
  return EXIT_SUCCESS;
}
