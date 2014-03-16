#include "vector.h"
int equalVector(Vector v1, Vector v2)
// return 0 if any attribute is different
// return 1 if all attributes are equal
{
  if (v1.x != v2.x) { return 0; }
  if (v1.y != v2.y) { return 0; }
  if (v1.z != v2.z) { return 0; }
  return 1;
}
