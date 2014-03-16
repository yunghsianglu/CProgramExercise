Node * List_insert(Node * head, int val)
{
  Node * ptr = Node_construct(val); 
  if (head == NULL)
    {
      return ptr;
    }
  if ((head -> value) > val)
    {
      ptr -> next = head; 
      return ptr;
    }
  head -> next = List_insert(head -> next, val);
  return head;
}

