// A static function can be called by functions in this file only.
// Functions outside this file cannot call it.
static Node * Node_construct(int val)
{
  Node * nd = malloc(sizeof(Node));
  nd -> value = val;
  nd -> next = NULL;
  return nd;
}

Node * List_insert(Node * head, int val)
{
  printf("insert %d\n", val);
  Node * ptr = Node_construct(val); 
  ptr -> next = head; // insert at the beginning 
  return ptr;   
}

