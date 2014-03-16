#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "puzzle.h"
#include "utility.h"
#define MAXMOVES 8
static int stateSize(const char * state)
{
  // the size is the square root of the state's length
  int len = strlen(state);
  int size = (int) sqrt(len);
  if ((size * size) == len)
    {
      return size;
    }
  return -1;
}

int main(int argc, char * * argv)
{
  if (argc < 3)
    {
      return EXIT_FAILURE;
    }
  char * state = strdup(argv[2]);
  int size = stateSize(state);
  if ((size < 2) || (size > 6))
    {
      return EXIT_FAILURE;
    }
  int valid;
  if (strcmp(argv[1], "1") == 0)
    {
      int nummove = strlen(argv[3]);
      valid = moveTiles(size, state, nummove, argv[3]);
      if (valid == 1)
	{
	  printf("%s\n", state);
	}
      free(state);
      return EXIT_SUCCESS;
    }
  int nummove = (int) strtol(argv[3], NULL, 10);
  if (strcmp(argv[1], "2") == 0)
    {
      if ((nummove <= 0) || (nummove > MAXMOVES))
	{
	  return EXIT_FAILURE;
	}
      int numstate = 0;
      char * * deststate;
      deststate = allStates(size, state, nummove, & numstate);
      while (numstate > 0)
	{
	  numstate --;
	  printoneD(size, deststate[numstate]);
	  free(deststate[numstate]);
	}
      free (deststate);
      free (state);
      return EXIT_SUCCESS;
    }
  if (strcmp(argv[1], "3") == 0)
    {
      char * moves = malloc(sizeof(char) * nummove);
      // nummove is the maximum number of moves
      // actualnum is the actual number of moves
      int actualnum = 0;
      solve(size, state, nummove, & actualnum, moves);
      int ind;
      printf("moves: ");
      if (actualnum == 0)
	{
	  printf("none");
	}
      for (ind = 0; ind < actualnum; ind ++)
	{
	  printf("%c", moves[ind]);
	}
      printf("\n");
      free(state);
      free (moves);
      return EXIT_SUCCESS;
    }
  return EXIT_FAILURE;
}
