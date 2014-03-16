int comparefunc(const void * arg1, const void * arg2)
{
  // convert void * to a known type
  const type * ptr1 = (const type *) arg1; 
  const type * ptr2 = (const type *) arg2;  
  const type val1 = * ptr1; // get the value from the address
  const type val2 = * ptr2;
  if (val1 < val2) // compare the value
    { return -1; }
  if (val1 == val2)
    { return 0; }
  return 1;
}
