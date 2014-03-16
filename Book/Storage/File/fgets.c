/*
 * use fgets to count the number of lines
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 81
int main(int argc, char * argv[])
{
  FILE * fptr;
  int numLine = 0;
  char oneLine[MAX_LINE_LENGTH];
  if (argc < 2)
    {
      printf("Need to provide the file's name.\n");
      return EXIT_FAILURE;
    }
  fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      printf("fopen fail.\n");
      return EXIT_FAILURE;
    }
  printf("The name of the file is %s.\n", argv[1]);
  while (fgets(oneLine, MAX_LINE_LENGTH, fptr) != NULL)
    {
      numLine ++;
    } 
  fclose(fptr);
  printf("The file has %d lines.\n", numLine);
  return EXIT_SUCCESS;
}
