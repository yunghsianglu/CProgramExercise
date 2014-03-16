#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

Person * Person_copy(Person * p); 
// create a new Person object by copying the attributes of p 
Person * Person_assign(Person * p1, Person * p2);
// p1 is already a Person object, make its attribute the same as p2's
// the attributes (deep copy)

Person * Person_copy(Person * p)
{
  return Person_construct(p -> year, p -> month, p -> date, p -> name);
}

Person * Person_assign(Person * p1, Person * p2)
{
  Person_destruct(p1);
  return Person_copy(p2);
}

int main(int argc, char * argv[])
{
  Person * p1 = Person_construct(1989, 8, 21, "Amy");
  Person * p2 = Person_construct(1991, 2, 17, "Jennifer");
  Person * p3 = Person_copy(p1); /* create p3 the first time */
  Person_print(p1);
  Person_print(p2);
  Person_print(p3);
  p3 = Person_assign(p3, p2);
  Person_print(p3);
  Person_destruct(p1);
  Person_destruct(p2);
  Person_destruct(p3);
  return EXIT_SUCCESS;
}

