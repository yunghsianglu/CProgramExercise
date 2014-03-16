void partition(int * arr, int ind, int left)
{
  int val;
  if (left == 0)
    {
      printPartition(arr, ind);
      return;
    }
  for (val = 1; val <= left; val ++)
    {
      int valid = 0;
      if (ind == 0) // no restriction for the first number
	{
	  valid = 1;
	}
      else
	{
	  valid = (arr[ind - 1] % 2) != (val % 2);
	}
      if (valid == 1)
	{
	  arr[ind] = val;
	  partition(arr, ind + 1, left - val);
	}
    }
}

