void swap (int * k, int * m)
{
  int s = * k;
  * k = * m;
  * m = s;
}

void f(void)
{
  int a = 83;
  int c = -74;
  swap (& a, & c);
}
