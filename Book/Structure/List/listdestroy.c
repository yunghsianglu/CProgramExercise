void List_destroy(Node * head)
{
  while (head != NULL)
    {
      Node * p = head -> next;
      free (head);
      head = p;
    }
}

void List_destroy2(Node * head)
{
  if (head == NULL)
    {
      return;
    }
  List_destroy2(head -> next);
  free (head); // must be after the recursive call
}

