#include <string.h>
/*
 * This function is inspired by the sample comparison function in
 * qsort's manual
 */
int cmpstringp(const void *arg1, const void *arg2)
{
  const char * const * ptr1 = (const char * *) arg1;
  const char * const * ptr2 = (const char * *) arg2;
  const char * str1 = * ptr1;
  const char * str2 = * ptr2;
  return strcmp(str1, str2);
}

