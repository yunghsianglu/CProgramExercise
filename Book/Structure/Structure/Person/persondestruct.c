#include "person.h"
#include <stdlib.h>
void Person_destruct(Person * p)
{
  // notice the order, p -> name must be freed before p is freed
  free (p -> name);
  free (p);
}
