//  Write a program to sum first ten natural numbers using while loop.

#include <stdio.h>

int main()
{
  int sum = 0;
  for (int i = 1; i < 11; i = i + 1)
  {
    sum = sum + i;
  }
  printf("The sum of first ten natural numbers is: %d\n", sum);

  return 0;
}