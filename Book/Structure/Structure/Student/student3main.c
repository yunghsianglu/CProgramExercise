/* file: student3main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student3.h"

int main(int argc, char * argv[])
{
  Student s1;
  strcpy(s1.name, "Amy Smith");
  s1.year = 3;
  s1.GPA = 3.6;
  printStudent(s1);
  return EXIT_SUCCESS;
}
