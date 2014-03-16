void incrarr(int * intarr, int len)
{
  int ind;
  for (ind = 0; ind < len; ind ++)
    {
      intarr[ind] ++;
    }
}
void f(void)
{
  int arr[5];
  arr[0] = 4;
  arr[1] = -7;
  arr[2] = 2;
  arr[3] = 3;
  arr[4] = 9;
  incrarr(arr, 5);
  /* RL */
}
