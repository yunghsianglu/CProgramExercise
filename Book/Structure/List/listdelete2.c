Node * List_delete2(Node * head, int val)
{
  printf("delete %d\n", val);
  if (head == NULL) 
    {
      return NULL;
    }

  if ((head -> value) == val)
    {
      Node * p = head -> next;
      free (head);
      return p;
    }

  head -> next = List_delete2(head -> next, val);
  return head; 
}

