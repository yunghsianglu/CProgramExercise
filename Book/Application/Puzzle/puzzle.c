#include "puzzle.h"
#include "utility.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
// return 1 if the move is valid
// return 0 if the move is invalid
static int oneMove(int size, char * * twoD, char move)
{
  // find the location of '-'
  // printf("oneMove %c\n", move);
  int dashrow = 0;
  int dashcol = 0;
  int found = 0;
  while ((found == 0) && (dashrow < size) && (dashcol < size))
    {
      if (twoD[dashrow][dashcol] == '-')
	{
	  found = 1;
	}
      else
	{
	  dashcol ++;
	  if (dashcol == size)
	    {
	      dashrow ++;
	      dashcol = 0;
	    }
	}
    }
  if (found == 0)
    {
      // invalid state
      return 0;
    }
  // new location of '-'
  int newrow;
  int newcol;
  switch (move)
    {
    case 'U':
      if (dashrow == 0)
	{
	  return 0;
	}
      newrow = dashrow - 1;
      newcol = dashcol;
      break;
    case 'D':
      if (dashrow == (size - 1))
	{
	  return 0;
	}
      newrow = dashrow + 1;
      newcol = dashcol;
      break;
    case 'L':
      if (dashcol == 0)
	{
	  return 0;
	}
      newrow = dashrow;
      newcol = dashcol - 1;
      break;
    case 'R':
      if (dashcol == (size - 1))
	{
	  return 0;
	}
      newrow = dashrow;
      newcol = dashcol + 1;
      break;
    default:
      return 0;
      break;
    }
  twoD[dashrow][dashcol] = twoD[newrow][newcol];
  twoD[newrow][newcol] = '-';
  return 1;
}

int moveTiles(int size, char * state, int nummove, char * moves)
{
  char * * twoD = allocateTwoD(size);
  oneD2twoD(size, state, twoD);
  // printtwoD(size, twoD);
  int ind = 0;
  int valid = 1;
  while ((ind < nummove) && (valid == 1))
    {
      valid = oneMove(size, twoD, moves[ind]);
      // printtwoD(size, twoD);
      ind ++;
    }
  twoD2oneD(size, state, twoD);
  releaseTwoD(size, twoD);
  return valid;
}

// root must not be NULL, it must store the initial state
static void generateHelper(int size, 
			   const char * srcstate,
			   char * moves, 
			   int index, 
			   int nummove,
			   TreeNode * root)
{
  const char direction[4] = {'R', 'D', 'L', 'U'}; // four directions
  if (index == nummove)
    {
      // a complete sequence of steps, try to move
      char * state = copyState(size, srcstate);
      int rtv = moveTiles(size, state, nummove, moves);
      if (rtv == 1)
	{
	  // valid move
	  Tree_insert(root, size, state, nummove, moves);
	}
      free (state);
      return;
    }
  int dir;
  for (dir = 0; dir < 4; dir ++)
    {
      moves[index] = direction[dir];
      generateHelper(size, srcstate, moves, index + 1, 
		     nummove, root);
    }
  
}				   

static TreeNode * generateAllStates(int size, 
				    const char * srcstate, 
				    int maxmove)
{
  TreeNode * tnroot = NULL;
  tnroot = Tree_insert(NULL, size, srcstate, 0, NULL);
  char * moves = malloc(sizeof(char) * maxmove);
  int nummove;
  for (nummove = 1; nummove <= maxmove; nummove ++)
    {
      generateHelper(size, srcstate, moves, 0, nummove, tnroot);
    }
  free (moves);
  return tnroot;
}

char * * allStates(int size, const char * srcstate, int nummove, 
		   int * numstate)
{
  (* numstate) = 0;
  TreeNode * tnroot = generateAllStates(size, srcstate, nummove);
  Tree_print(tnroot);
  char * * reachableState;
  * numstate = Tree_size(tnroot);
  int height = Tree_height(tnroot);
  // printf("There are %d states and the tree's height is %d\n",
  // * numstate, height);
  if ((* numstate) == 0)
    {
      return NULL;
    }
  reachableState = malloc(sizeof(char *) * (* numstate));
  int ind = 0;
  Tree_fillState(tnroot, reachableState, & ind);
  Tree_destroy(tnroot);
  return reachableState;
}

void solve(int size, const char * srcstate, int maxmove, 
	   int * nummove, char * moves)
{
  int length = size * size;
  TreeNode * tnroot = generateAllStates(size, srcstate, maxmove);
  char * solvedstate = malloc(sizeof(char) * length);
  int ind;
  for (ind = 0; (ind < length - 1) && (ind < 9); ind ++)
    {
      solvedstate[ind] = ind + '1';
    }
  for (ind = 9; ind < length - 1; ind ++)
    {
      solvedstate[ind] = ind - 9 + 'A';
    }
  solvedstate[length - 1] = '-';
  TreeNode * tn = Tree_search(tnroot, solvedstate);
  if (tn == NULL)
    {
      // cannot find solution
      * nummove = -1;
    }
  else
    {
      * nummove = tn -> nummove;
      for (ind = 0; ind < (* nummove); ind ++)
	{
	  moves[ind] = tn -> moves[ind];
	}
    }
  free(solvedstate);
  Tree_destroy(tnroot);
}
