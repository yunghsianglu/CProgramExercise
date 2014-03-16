void printPartition(int * arr, int length)
{
  int ind;
  for (ind = 0; ind < length - 1; ind ++)
    {
      if (arr[ind] >= arr[ind + 1])
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

