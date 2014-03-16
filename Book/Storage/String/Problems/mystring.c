#include "mystring.h"
#include <ctype.h>

int my_strlen(const char * str)
{
  int len = 0;
  while (str[len] != '\0') 
    {
      len++;
    }
  return len;
}

int my_countchar(const char * str, char ch)
{
  int count = 0;
  while (* str != '\0') 
    {
      if (* str == ch) 
	{
	  count++;
	}
      str ++;
    }
  return count;
}

void my_strupper(char * str)
{
  while (* str != '\0') 
    {
      * str = toupper(* str);
      str++;
    }
}
