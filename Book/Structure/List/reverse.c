Node * List_reverse(Node * head)
{
  if (head == NULL)
    {
      // empty list, nothing to do
      return NULL;
    }
  Node * orighead = head;
  Node * revhead = NULL;
  Node * origsec; 
  while (orighead != NULL)
    {
      origsec = orighead -> next;
      orighead -> next = revhead;
      revhead = orighead;
      orighead = origsec;
    }
  return revhead;
}
