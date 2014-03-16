#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
  // need three file names: two inputs and one output 
  if (argc < 4)
    {
      return EXIT_FAILURE;
    }
  FILE * fin1;
  FILE * fin2;
  // open the two input files
  fin1 = fopen(argv[1], "r");
  if (fin1 == NULL)
    {
      return EXIT_FAILURE;
    }
  fin2 = fopen(argv[2], "r");
  if (fin2 == NULL)
    {
      fclose (fin1); // need to close opened file
      return EXIT_FAILURE;
    }
  // open the output file
  FILE * fout;
  fout = fopen(argv[3], "w");
  if (fout == NULL)
    {
      fclose (fin1); 
      fclose (fin2); 
      return EXIT_FAILURE;
    }
  
  int val1;
  int val2;
  int in1ok = 1;
  int in2ok = 1;
  // continue as long as one file still has numbers
  while ((in1ok == 1) || (in2ok == 1))
    {
      val1 = 0; // need to reset because fscanf may fail next time
      val2 = 0;
      if (fscanf(fin1, "%d", & val1) != 1) // do not use == 0
	{
	  in1ok = 0;
	}
      if (fscanf(fin2, "%d", & val2) != 1)
	{
	  in2ok = 0;
	}
      if ((in1ok == 1) || (in2ok == 1))
	{
	  fprintf(fout, "%d\n", val1 + val2);
	}
    }
  /* close the files */
  fclose (fin1);
  fclose (fin2);
  fclose (fout);

  return EXIT_SUCCESS;
}
