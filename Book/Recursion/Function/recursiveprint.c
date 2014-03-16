/*
  file: recursiveprint.c
  purpose: show the values before and after recursive calls 
*/
#include <stdio.h>
#include <stdlib.h>
void f(int n)
{
    int iter;
    if (n <= 0) { return; }
    if (n == 1)
   {
       printf("1 0\n");
       return;
   }
   for (iter = 1; iter < n; iter ++)
   {
     printf("%d %d\n", iter,  n - iter);
     f(n - iter);
     printf("%d %d\n", iter,  n - iter);
   }
}

int main(int argc, char * argv[])
{
  f(3);
  return EXIT_SUCCESS;
}
