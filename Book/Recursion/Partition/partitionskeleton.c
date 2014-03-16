void partition(int * arr, int ind, int left)
{
  int val;
  for (val = 1; val <= left; val ++)
    {
      arr[ind] = val;
      partition(arr, ind + 1, left - val);
    }
}

