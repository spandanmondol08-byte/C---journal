// Write a program to check whether a given number is prime or not using loops.

#include <stdio.h>

int main()
{
  int n;
  printf("Enter the Number : ");
  scanf("%d", &n);
  int c = 0;
  for (int i = 1; i < n; i = i + 1)
  {
    if (n % i == 0)
    {
      c = c + 1;
    }
  }
  if (n == 1 || n == 0)
  {
    printf("%d is neither Prime nor Composite", n);
  }
  else if (c == 1)
  {
    printf("%d is Prime number", n);
  }
  else
  {
    printf("%d is Composite number", n);
  }

  return 0;
}