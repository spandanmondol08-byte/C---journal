#include <stdio.h>

int main()
{
  int a = 5;
  int b = 43;
  int mul = a * b;
  int add = a + b;
  int subs = a - b;
  int div = a / b;
  int rem = a % b;
  printf("The multiplication is %d\n", mul);
  printf("The division is %d\n", div);
  printf("The addition is %d\n", add);
  printf("The subtraction is %d\n", subs);
  printf("The remainder is %d\n", rem);

  return 0;
}