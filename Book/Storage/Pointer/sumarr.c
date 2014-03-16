int sumarr(int * intarr, int len)
{
  int ind;
  int sum2 = 0; // remember to initialize to zero
  for (ind = 0; ind < len; ind ++)
    {
      sum2 += intarr[ind];
    }
  return sum2;
}
void f(void)
{
  int sum = 0;
  int arr[5];
  arr[0] = 4;
  arr[1] = -7;
  arr[2] = 2;
  arr[3] = 3;
  arr[4] = 9;
  sum = sumarr(arr, 5);
  /* RL */
  printf("sum = %d\n", sum);
}
