// Create a two-dimensional vector using structures in C.
#include <stdio.h>
struct vector
{
  int i;
  int j;
};

int main() {
  struct vector v;
  v.i=-5;
  v.j=10;
  printf("The vectors are : %d i + %d j",v.i,v.j);

  return 0;
}