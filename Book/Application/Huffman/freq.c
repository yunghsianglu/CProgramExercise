#include "constant.h"
#include "freq.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int countFrequency(char * filename, CharFreq * frequencies)
{
  FILE * fptr = fopen(filename, "r");
  int count = 0;
  if (fptr == NULL)
    {
      return count;
    }
  while (! feof (fptr))
    {
      int onechar = fgetc(fptr);
      if (onechar != EOF)
	{
	  count ++;
	  frequencies[onechar].value = (char) onechar;
	  frequencies[onechar].freq ++;
	}
    }
  fclose (fptr);
  return count;
}

void printFrequency(CharFreq * frequencies)
{
  int ind;
  for (ind = 0; ind < NUMLETTER; ind ++)
    {
      printf("%d %d\n", frequencies[ind].value, 
	     frequencies[ind].freq);
    }
  printf("------------------------\n");
}

static int compareFreq(const void * p1, const void * p2)
{
  const CharFreq * ip1 = (const CharFreq *) p1;
  const CharFreq * ip2 = (const CharFreq *) p2;
  const int iv1 = ip1 -> freq;
  const int iv2 = ip2 -> freq;
  return (iv1 - iv2);
}

void sortFrequency(CharFreq * frequencies)
{
  qsort(frequencies, NUMLETTER, sizeof(CharFreq), compareFreq);
}
