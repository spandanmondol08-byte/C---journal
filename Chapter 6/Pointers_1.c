#include <stdio.h>

int main()
{
  int i = 123;
  int *j = &i; // j is pointer of i

  printf("The address of i is : %p\n", &i);
  printf("The address stored in j is: %p\n", j);
  printf("The address of j is : %p\n", &j);
  printf("The value stored is : %d\n", *j);

  return 0;
}