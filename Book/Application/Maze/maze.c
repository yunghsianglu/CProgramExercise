/* maze.c */

#include "maze.h"
#include <stdio.h>
#include <stdlib.h>
/* 
   ================================================================ 
*/
/* declaration of static functions. A static function can be called by
   another function in the same file. A static function cannot be
   called by any function outside this file. */

/* check whether ptr is NULL, if so, print an error message and
   exit */
static void checkMallocFailure(void * ptr, char * message);

/* find the length of a line in a file (EOF or '\n') */
static int fineLineLength(FILE * fh);

/* Find the numbers of rows and columns.  If the maze is not
   rectangular, use the longest row for the number of column */
static void Maze_findSize(FILE * fh, int * numRow, int * numCol);

/* 
   ================================================================ 
*/
static void checkMallocFailure(void * ptr, char * message)
{
  if (ptr == NULL) /* malloc fail */
    {
      printf("malloc for %s fail\n", message);
      exit (EXIT_FAILURE);
    }
}

static int fineLineLength(FILE * fh)
{
  int ch;
  int length = 0;
  if (feof(fh)) { return -1; }
  do
    {
      ch = fgetc(fh); /* read one character */
      if ((ch == EOF) || (ch == '\n'))
	{ return length; } /* do not include '\n' */
      length ++;
    }
}

static void Maze_findSize(FILE * fh, int * numRow, int * numCol)
{
  int row = 0;
  int col = 0;
  int maxCol = 0;
  do
    {
      col = findLineLength(fh);
      if (col != -1)
	{
	  if (maxCol < col) { maxCol = col; }
	  row ++; 	  
	}
    } while (col != -1); 
  * numRow = row;
  * numCol = maxCol;
}

Maze * Maze_construct(char * fileName)
{
  int numRow = 0;
  int numCol = 0;
  int row, col;
  int ch;

  FILE * fh = fopen(fileName, "r");
  if (fh == 0)
    {
      fprintf(stderr, "open %s fail\n", fileName);
      return NULL;
    }
  Maze_findSize(fh, & numRow, & numCol);

  Maze * mz = malloc(sizeof(Maze));
  checkMallocFailure(mz, "mz");
  mz -> numRow = numRow;
  mz -> numCol = numCol;

  /* create a two-dimensional array to store the cells */
  mz -> maze = malloc(numRow * sizeof(int *));
  checkMallocFailure(mz -> maze, "mz -> maze");
  for (row = 0; row < numRow; row ++)
    {
      mz -> maze[row] = malloc(numCol * sizeof(int));
      checkMallocFailure(mz -> maze[row], "mz -> maze[row]");
      /* initialize the cells to invalid */
      for (col = 0; col < numCol; col ++)
	{
	  (mz -> maze)[row][col] = INVALIDSYMBOL;
	}
    }

  /* move fh to the beginning */ 
  fseek(fh, 0, SEEK_SET);

  /* read the file again and fill the two-dimensional array */
  row = 0;
  while ((! feof(fh)) && (ch != EOF) && (row < numRow))
    {
      /* fill one row */
      col = 0;
      do 
	{
	  ch = fgetc(fh);
	  if (ch != EOF) 
	    {
	      /* notice that '\n' is also stored */
	      (mz -> maze)[row][col] = ch;
	      switch (ch)
		{
		case STARTSYMBOL:
		  mz -> startRow = row;
		  mz -> startCol = col;
		  mz -> curRow = row;
		  mz -> curCol = col;
		  break;
		case EXITSYMBOL:
		  mz -> exitRow = row;
		  mz -> exitCol = col;
		  break;
		}
	      col ++;
	    }
	} while ((ch != EOF) && (ch != '\n'));
      /* checking '\n" allows the program to handle non-rectangular
	 mazes */
      row ++;
    }
  fclose(fh);
  return mz;
}

/* release the memory */
void Maze_destruct(Maze * mz)
{
  int row;
  for (row = 0; row < (mz -> numRow); row ++)
    { free ((mz->maze)[row]); }
  free(mz);
}

void Maze_print(Maze * mz)
{
  int row;
  int col;
  for (row = 0; row < (mz -> numRow); row ++)
    {
      for (col = 0; col < (mz -> numCol); col ++)
	{
	  if (((mz -> curRow) == row) && ((mz -> curCol) == col))
	    {
	      if (((mz -> curRow) == (mz -> startRow)) && 
		  ((mz -> curCol) == (mz -> startCol)))
		{
		  printf("s");
		}
	      else
		{
		  printf("c");
		}
	    }
	  else
	    {
	      printf("%c", (mz -> maze)[row][col]);
	    }
	}
      printf("\n");
    }
}

static int canMove(Maze * mz, int row, int col, int dir, int found)
{
  int nextRow = row;
  int nextCol = col;
  if (found == 1) { return 0; }
  switch (dir)
    {
    case NORTH:
      if (row <= 0) { return 0; }
      nextRow --;
      break;
    case SOUTH:
      if (row >= ((mz -> numRow) - 1)) { return 0; }
      nextRow ++;
      break;
    case WEST:
      if (col <= 0) { return 0; }
      nextCol --;
      break;
    case EAST:
      if (col >= ((mz -> numCol) - 1)) { return 0; }
      nextCol ++;
      break;
    }
  if ((mz->maze)[nextRow][nextCol] == ' ') { return 1; }
  if ((mz->maze)[nextRow][nextCol] == 'E') { return 1; }
  return 0;
}

static void reVisit(int progress, int found, int row, int col)
{
  if (progress == FORWARD) { return; }
  if (found == 1) { return; }
  printf("Move to (%d,%d)\n", row, col); 
}

void Maze_traverse(Maze * mz, int row, int col, 
		   int dir, int * progress, int * found)
{
  printf("Move to (%d,%d)\n", row, col);
  mz -> curRow = row;
  mz -> curCol = col;
  /* Maze_print(mz); */
  if ((mz -> maze)[row][col] == 'E') /* found exit */
    { 
      * found = 1;
      return; 
    }
  /* clockwise, right - down - left - up */
  if ((dir != WEST) && (canMove(mz, row, col, EAST, * found)))
    {
      /* can go right */
      * progress = FORWARD;
      Maze_traverse(mz, row, col + 1, EAST, progress, found);
      reVisit(* progress, * found, row, col);
    }
  if ((dir != NORTH) && (canMove(mz, row, col, SOUTH, * found)))
    {
      /* can go down */
      * progress = FORWARD;
      Maze_traverse(mz, row + 1, col, SOUTH, progress, found);
      reVisit(* progress, * found, row, col);
    }
  if ((dir != EAST) && (canMove(mz, row, col, WEST, * found)))
    {
      /* can go left */
      * progress = FORWARD;
      Maze_traverse(mz, row, col - 1, WEST, progress, found);
      reVisit(* progress, * found, row, col);
    }
  if ((dir != SOUTH) && (canMove(mz, row, col, NORTH, * found)))
    {
      /* can go up */
      * progress = FORWARD;
      Maze_traverse(mz, row - 1, col, NORTH, progress, found);
      reVisit(* progress, * found, row, col);
    }
  /* reach a deadend, must backtrack */
  * progress = BACKWARD;
}


