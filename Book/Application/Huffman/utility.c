#include "utility.h"
static void printByte(unsigned char onebyte)
{
  unsigned char mask = 0x80;
  while (mask > 0)
    {
      printf("%d", (onebyte & mask) == mask);
      mask >>= 1;
    }
  printf("\n");
}

int writeBit(FILE * fptr, unsigned char bit, 
	     unsigned char * whichbit, unsigned char * curbyte)
  
{
  if ((* whichbit) == 0)
    {
      // reset
      * curbyte = 0;
    }
  // shift the bit to the correct location
  unsigned char temp = bit << (7 - (* whichbit));
  * curbyte |= temp;
  int value = 0;
  if ((* whichbit) == 7)
    {
      int ret;
      ret = fwrite(curbyte, sizeof(unsigned char), 1, fptr);
      // printByte(* curbyte); // for debugging
      if (ret == 1)
	{
	  value = 1;
	}
      else
	{
	  value = -1;
	}
    }
  * whichbit = ((* whichbit) + 1) % 8;
  return value;
}

int padZero(FILE * fptr, unsigned char * whichbit, unsigned char * curbyte)
{
  int rtv;
  while ((* whichbit) != 0)
    {
      rtv = writeBit(fptr, 0, whichbit, curbyte);
      if (rtv == -1)
	{
	  return -1;
	}
    }
  return rtv;
}

int readBit(FILE * fptr, unsigned char * bit, 
	    unsigned char * whichbit, unsigned char * curbyte)
  
{
  int ret = 1;
  if ((* whichbit) == 0)
    {
      // read a byte from the file
      ret = fread(curbyte, sizeof(unsigned char), 1, fptr);
    }
  if (ret != 1)
    {
      // read fail
      return -1;
    }
  // shift the bit to the correct location
  unsigned char temp = (* curbyte) >> (7 - (* whichbit));
  temp = temp & 0X01; // get only one bit, ignore the other bits
  // increase by 1
  * whichbit = ((* whichbit) + 1) % 8;
  * bit = temp;
  return 1;
}
