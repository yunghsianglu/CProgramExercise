Node * List_search(Node * head, int val)
{
  Node * ptr = head;
  while (ptr != NULL)
    {
      if ((ptr -> value) == val)
	{
	  return ptr;
	}
      ptr = ptr -> next;
    }
  return ptr; // must be NULL
}
