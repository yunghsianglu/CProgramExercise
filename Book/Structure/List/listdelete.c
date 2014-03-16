Node * List_delete(Node * head, int val)
{
  printf("delete %d\n", val);
  Node * p = head;
  if (p == NULL) // empty list, do nothing 
    {
      return p;
    }

  // delete the first node (i.e. head node)? 
  if ((p -> value) == val)
    {
      p = p -> next;
      free (head);
      return p;
    }

  // not deleting the first node 

  Node * q = p -> next;
  while ((q != NULL) && ((q -> value) != val))
    {
      // check whether q is NULL before checking q -> value 
      p = p -> next;
      q = q -> next;
    }
  if (q != NULL) 
    { 
      // delete the node whose value is val 
      p -> next = q -> next;
      free (q);
    }
  return head; 
}

