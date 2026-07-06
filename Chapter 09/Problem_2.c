// Write a function ‘sumVector’ which returns the sum of two vectors passed to it.
// The vectors must be two–dimensional.

#include <stdio.h>
struct vector
{
  int i;
  int j;
};
int sumi;
int sumj;
void sumVector(struct vector v1,struct vector v2)
{
  sumi =v1.i + v2.i;
  sumj =v1.j + v2.j;
}

int main() {
  struct vector v1;
  v1.i=-5;
  v1.j=10;
  struct vector v2;
  v2.i=4;
  v2.j=-9;
  sumVector(v1,v2);
  printf("The sum of vectors are : %d i + %d j",sumi,sumj);

  return 0;
}