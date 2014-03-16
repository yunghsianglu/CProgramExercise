void printPartition(int * arr, int length)
{
  int ind;
  // check whether any number is even
  // if an even number is used, do not print anything
  for (ind = 0; ind < length; ind ++)
    {
      if ((arr[ind] % 2) == 0)
	{
	  return;
	}
    }
  
  for (ind = 0; ind < length - 1; ind ++)
    {
      printf("%d + ", arr[ind]);
    }
  printf("%d\n", arr[length - 1]);
}

