void partition(int * arr, int ind, int left)
{
  int val;
  if (left == 0)
    {
      printPartition(arr, ind);
      return;
    }
  int min = 1;
  if (ind != 0) 
    {
      min = arr[ind - 1] + 1;
    }
  for (val = min; val <= left; val ++)
    {
	  arr[ind] = val;
	  partition(arr, ind + 1, left - val);
	}
    }
}

