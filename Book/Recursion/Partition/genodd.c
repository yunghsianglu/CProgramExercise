void partition(int * arr, int ind, int left)
{
  int val;
  if (left == 0)
    {
      printPartition(arr, ind);
      return;
    }
  for (val = 1; val <= left; val += 2) // odd numbers only
    {
      arr[ind] = val;
      partition(arr, ind + 1, left - val);
    }
}

