// Factorial using recursion

#include <stdio.h>

int factorial(int n)
{
  if (n == 1 || n == 0) // Base condition
  {
    return 1;
  }
  return factorial(n - 1) * n;
}


int main()
{
  int n;
  printf("Enter the number : ");
  scanf("%d", &n);
  int c = factorial(n);
  printf("Factorial of %d is : %d", n, c);

  return 0;
}