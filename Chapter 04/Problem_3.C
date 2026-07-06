// Write a program to print multiplication table of 10 in reversed order.

#include <stdio.h>

int main()
{
  int n = 10;
  printf("----------------------------------MULTIPLICATION TABLE OF %d-----------------------------------\n", n);
  for (int i = 10; i > 0; i = i - 1)
  {
    int x = i * n;
    printf("%d X %d = %d\n", n, i, x);
  }

  return 0;
}