# include <stdio.h>
# include <stdlib.h>
# include <string.h>
typedef struct
{
  int size; // how many digits can be stored
  int used; // how many digits are actually stored
  unsigned char * data; // store the digits
  // each byte can store two digits
} DecPack;

// create a DecPack object with the given size
// sz is the maximum number of decimal digits this object can store
DecPack * DecPack_create(int sz)
{
  // allocate memory for DecPack 
  // 1. <--- FILL CODE --->
  /* A: */ DecPack * dp = malloc(sizeof(int));

  /* B: */ DecPack * dp = malloc(sizeof(int) * sz);

  /* C: */ DecPack   dp = malloc(sizeof(DecPack));

  /* D: */ DecPack * dp = malloc(sizeof(DecPack));

  /* E: */ DecPack * dp -> data = malloc(sizeof(unsigned char) * sz);

  // check whether allocation fails
  if (dp == NULL)
    {
      return NULL;
    }
  // initialize size to sz and used to 0
  dp -> size = sz;
  dp -> used = 0;
  // allocate memory for data, each element can store two digits
  // can store two digits
  // allocate enough memory, no more than necessary
  // 2. <--- FILL CODE --->
  /* A: */ dp -> data = malloc(sizeof(unsigned char) * sz);
  
  /* B: */ dp -> data = malloc(sizeof(int));

  /* C: */ dp -> data = malloc(sizeof(DecPack));

  /* D: */
  {
    if ((sz % 2) == 1) { sz --; }
    dp -> data = malloc(sizeof(unsigned char) * (sz / 2));
  }

  /* E: */
  {
    if ((sz % 2) == 1) { sz ++; }
    dp -> data = malloc(sizeof(unsigned char) * (sz / 2));
  }
  // check whether allocation fails
  if (dp -> data == NULL)
    {
      free (dp);
      return NULL;
    }
  // return the allocate memory
  return dp;
}

// Insert a decimal digit into the DecPack object. The new digit is at
// the end of the sequence
// *** You can assume 0 <= val <= 9 ***
void DecPack_insert(DecPack * dp, int val)
{
  // if the object is empty, do nothing
  if (dp == NULL) { return; }

  // if val < 0 or val > 9, ignore and do nothing
  if ((val < 0) || (val > 9)) { return; }

  // If the allocated memory is full, double the size and allocate
  // memory, copy the data, release the old memory, and insert the new
  // digit
  int used = dp -> used;
  if (used == dp -> size) 
    {
      // allocate memory for double size 
      // allocate enough memory, no more than necessary
      // Hint: each element of data can store two digits
      // 3. <---- FILL CODE ----> 
      /* A: */
      {
	unsigned char * newdata =  malloc(sizeof(unsigned char) * 
					  (dp -> size));
	int iter;
	(dp -> size) *= 2;
	for (iter = 0; iter < used; iter ++)
	  {
	    newdata[iter / 2] = dp -> data[iter / 2];
	  }
	free (dp -> data);
	dp -> data = newdata;
      }

      /* B: */
      {
	unsigned char * newdata = malloc(sizeof(unsigned char) * 
					 (dp -> size));
	int iter;
	for (iter = 0; iter < used; iter ++)
	  {
	    newdata[iter / 2] = dp -> data[iter / 2];
	  }
	free (dp -> data);
	dp -> data = newdata;
      }

      /* C: */
      {
	unsigned char * newdata = malloc(sizeof(unsigned char) * 
					 (dp -> size));
	int iter;
	free (dp -> data);
	(dp -> size) *= 2;
	dp -> data = newdata;
      }

      /* D: */
      {
	(dp -> size) *= 2;
	dp -> data = malloc(sizeof(unsigned char) * (dp -> size));
      }

      /* E: */
      {
	unsigned char * newdata = malloc(sizeof(unsigned char) * 
					 (dp -> size));
	int iter;
	free (dp -> data);
	for (iter = 0; iter < used; iter ++)
	  {
	    newdata[iter / 2] = dp -> data[iter / 2];
	  }
	(dp -> size) *= 2;
	dp -> data = newdata;
      }
    }
  // Hint: Make sure you do not lose the data already stored in
  // DecPack

  if ((used % 2) == 0) // it is even
    {
      // 4. <---- FILL CODE ---->
      /* A: */ dp -> data[used]     = (val << 4);
      /* B: */ dp -> data[used / 2] = (val << 4);
      /* C: */ dp -> data[used / 2] = (val >> 4);
      /* D: */ dp -> data[used / 2] = (val & 0XF0);
      /* E: */ dp -> data[used]     = (val & 0X0F);
    }
  else // used is odd number
    {
      // 5. <---- FILL CODE ----> 
      /* A: */ dp -> data[used]     += val;
      /* B: */ dp -> data[used / 2] += (val >> 4);
      /* C: */ dp -> data[used / 2] += val;
      /* D: */ dp -> data[used]     += (val & 0X80);
      /* E: */ dp -> data[used / 2] += (val << 4);
    }
  (dp -> used) ++;
}

// delete and return the last digit in the DecPack object
// do not shrink the data array even if nothing is stored
// if the object has no value, return -1
int DecPack_delete(DecPack * dp)
{
  // if the object is empty, do nothing
  if (dp == NULL) { return -1; }
  // return -1 if the DecPack object stores no data
  if ((dp -> used) == 0) { return -1; }

  int val;
  (dp -> used) --;
  int used = dp -> used;
  // Hint: make sure the returned digit is between 0 and 9
  if ((used % 2) == 0) // it is even
    {
      // 6. <---- FILL CODE ----> 
      /* A: */ val = (dp -> data[used / 2]) >> 4;
      /* B: */ val = (dp -> data[used / 2]) & 0X0F;
      /* C: */ val = (dp -> data[used / 2]) << 4;
      /* D: */ val = (dp -> data[used]) & 0X0F;
      /* E: */ val = (dp -> data[used]) & 0XF0;
    }
  else // is odd
    {
      // 7. <---- FILL CODE ----> 
      /* A: */ val = (dp -> data[used / 2]) >> 4;
      /* B: */ val = (dp -> data[used / 2]) & 0X0F;
      /* C: */ val = (dp -> data[used / 2]) << 4;
      /* D: */ val = (dp -> data[used]) & 0X0F;
      /* E: */ val = (dp -> data[used / 2]) & 0XF0;
    }
  // return the digit
  return val;
}

// print the digits stored in the object, the first inserted digit
// should be printed the first
// make sure the printed digits are between '0' and '9'
// This function does not print invisible characters
void DecPack_print(DecPack * dp)
{
  // if the object is empty, do nothing
  if (dp == NULL) { return; }
  int iter;
  int used = dp -> used;
  
  // go through every digit stored in the data attribute
  for (iter = 0; iter < used; iter ++)
    {
      if ((iter % 2) == 0)
	{
	  // 8. <---- FILL CODE ----> 
	  A. printf("%d", (dp-> data[iter] << 4));
	  B. printf("%d", (dp-> data[iter] >> 4));
	  C. printf("%c", (dp-> data[iter / 2]));
	  D. printf("%c", (dp-> data[iter / 2] & 0X80));
	  E. printf("%d", (dp-> data[iter / 2] >> 4));
	}
      else
	{
	  // 9. <---- FILL CODE ----> 
	  A. printf("%d", (dp-> data[iter / 2] >> 4));
	  B. printf("%d", (dp-> data[iter / 2] & 0X0F));
	  C. printf("%c", (dp-> data[iter / 2] & 0XF0));
	  D. printf("%c", (dp-> data[iter] & 0XFF));
	  E. printf("%d", (dp-> data[iter] << 4));
	}	
    }
  printf("\n");
}

// destroy the whole DecPack object, release all memory
void DecPack_destroy(DecPack * dp)
{
  // if the object is empty, do nothing
  if (dp == NULL) { return; }
  // release the memory for the data
  // release the memory for the object
  // 10. <---- FILL CODE ----> 
  /* A: */
  {
    free ((unsigned char ) dp -> data);
    free ((DecPack ) dp);
  }
  /* B: */
  {
    free (dp);
    free (dp -> data);
  }
  /* C: */
  {
    free (dp -> data);
    free (dp);
  }
  /* D: */
  {
    free (dp -> data);
  }
  /* E: */
  {
    free (dp);
  }
}

int main ( int argc , char * * argv )
{
  DecPack * dp = DecPack_create(5);
  int iter;
  for (iter = 0; iter < 21 ; iter ++)
    {
      DecPack_insert(dp, iter % 10);
    }
  DecPack_print(dp);
  for (iter = 0; iter < 7 ; iter ++)
    {
      printf("delete %d\n", DecPack_delete(dp));
    }
  DecPack_print(dp);
  for (iter = 0; iter < 6 ; iter ++)
    {
      DecPack_insert(dp, iter % 10);
    }
  DecPack_print(dp);
  for (iter = 0; iter < 6 ; iter ++)
    {
      printf("delete %d\n", DecPack_delete(dp));
    }
  DecPack_print(dp);
  DecPack_destroy(dp);
  return EXIT_SUCCESS ;
}
 
