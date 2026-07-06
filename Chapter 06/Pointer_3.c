// POINTER TO POINTER

#include <stdio.h>

int main() {
  int i = 176;
  int *j = &i; // j is pointer of i
  int **k = &j; // k is pointer to j (Pointer to Pointer)
  printf("The address of i is : %p\n", j);
  printf("The address of j is: %p\n", k);
  printf("The value stored in j is : %d\n", **k);
  printf("The value stored in i is : %d\n", *j);

  return 0;
}
