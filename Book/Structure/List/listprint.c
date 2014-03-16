void List_print(Node * head)
{
  printf("\nPrint the whole list:\n");
  while (head != NULL)
    {
      printf("%d ", head -> value);
      head = head -> next;
    }
  printf("\n\n");
}

static void List_print2Help(Node * head)
{
  if (head == NULL)
    {
      return;
    }
  printf("%d ", head -> value);
  List_print2Help(head -> next);
}

void List_print2(Node * head)
{
  printf("\nPrint the whole list:\n");
  List_print2Help(head);
  printf("\n\n");
}
