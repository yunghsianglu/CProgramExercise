#include "utility.h"
#include <stdlib.h>
#include <stdio.h>
void twoD2oneD(int size, char * oneD, char * * twoD)
{
  int ind;
  for (ind = 0; ind < (size * size); ind ++)
    {
      int row = ind / size;
      int col = ind % size;
      oneD[ind] = twoD[row][col];
    }
}

void oneD2twoD(int size, char * oneD, char * * twoD)
{
  int ind;
  for (ind = 0; ind < (size * size); ind ++)
    {
      int row = ind / size;
      int col = ind % size;
      twoD[row][col] = oneD[ind];
    }
}

char * * allocateTwoD(int size)
{
  char * * state;
  state = malloc(sizeof(char *) * size);
  int ind;
  for (ind = 0; ind < size; ind ++)
    {
      state[ind] = malloc(sizeof(char) * size);
    }
  return state;
}

void releaseTwoD(int size, char * * twoD)
{
  int ind;
  for (ind = 0; ind < size; ind ++)
    {
      free (twoD[ind]);
    }
  free (twoD);
}

void printoneD(int size, char * oneD)
{
  int ind;
  for (ind = 0; ind < (size * size); ind ++)
    {
      printf("%c", oneD[ind]);
    }
  printf("\n\n");
}

void printtwoD(int size, char * * twoD)
{
  int row;
  int col;
  for (row = 0; row < size; row ++)
    {
      for (col = 0; col < size; col ++)
	{
	  printf("%c", twoD[row][col]);
	}
      printf("\n");
    }
  printf("\n");
}

char * copyState(int size, const char * srcstate)
{
  // cannot use strdup because state may not end with '\0'
  int length = size * size;
  char * state = malloc(sizeof(char) * length);
  int ind;
  for (ind = 0; ind < length ; ind ++)
    {
      state[ind] = srcstate[ind];
    }
  return state;
}

