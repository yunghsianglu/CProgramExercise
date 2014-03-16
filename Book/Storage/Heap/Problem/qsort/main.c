/*
 * main.c
 */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANGE 10000
int comparefunc(const void * arg1, const void * arg2) // for integer
{
  const int * ptr1 = (const int *) arg1; 
  const int * ptr2 = (const int *) arg2;  
  int val1 = * ptr1; 
  int val2 = * ptr2;
  printf("comparefunc: %d %d\n", val1, val2);
  if (val1 < val2)  { return -1; }
  if (val1 == val2) { return 0; }
  return 1;
}

void printArray(int * arr, int size)
{
  int ind;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%d ", arr[ind]);
    }
  printf("\n");
}

int main(int argc, char * * argv)
{
  if (argc != 2)
    {
      return EXIT_FAILURE;
    }
  int size = strtol(argv[1], NULL, 10);
  if (size <= 0)
    {
      return EXIT_FAILURE;
    }    
  int * arr;
  arr = malloc(sizeof(int) * size);
  if (arr == NULL)
    {
      return EXIT_FAILURE;
    }
  int ind;
  srand(time(NULL)); // set the seed
  for (ind = 0; ind < size; ind ++)
    {
      arr[ind] = rand() % RANGE;
    }
  printArray(arr, size);
  qsort(& arr[0], size, sizeof(int), comparefunc);
  printArray(arr, size);
  free (arr);
  return EXIT_SUCCESS;
}

