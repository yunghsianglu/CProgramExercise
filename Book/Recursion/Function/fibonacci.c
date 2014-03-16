/* file: fibonacci.c
   purpose: find the maximum depth of the call stack for computing
   Fibonacci numbers
 */
#include <stdio.h>
#include <stdlib.h>
int fib(int n, int depth, int * maxsize)
{
  if ((*maxsize) < depth)
    {
      (*maxsize) = depth;
    }
  if ((n == 0) || (n == 1))
    {
      return 1;
    }
  int a = fib(n - 1, depth + 1, maxsize);
  int b = fib(n - 2, depth + 1, maxsize);
  return (a + b);
}

int main(int argc, char * argv[])
{
  if (argc != 2)
    {
      printf("need 1 integers.\n");
      return EXIT_FAILURE;
    }
  int n, val;
  int maxsize = 1;
  n = (int) strtol(argv[1], NULL, 10);
  val = fib(n, 0, & maxsize);
  printf("fib(%d) = %d. maxsize = %d\n", n, val, maxsize);
  return EXIT_SUCCESS;
}
