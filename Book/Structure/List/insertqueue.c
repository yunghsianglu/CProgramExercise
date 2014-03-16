Node * List_insert(Node * head, int val)
{
  if (head == NULL)
    {
      return Node_construct(val); 
    }
  head -> next = List_insert(head -> next, val);
  return head;   
}

