#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LINE_LENGTH 80
int main(int argc, char ** argv)
{
  if (argc < 2)
    {
      return EXIT_FAILURE;
    }
  FILE * fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      return EXIT_FAILURE;
    }
  char name[LINE_LENGTH];
  srand(time(NULL));
  while (fgets(name, LINE_LENGTH, fptr) != NULL)
    {
      printf("%d ", (int) (random() % 100 + 1));
      printf("%s", name);
    }
  fclose (fptr);
  return EXIT_FAILURE;
}
