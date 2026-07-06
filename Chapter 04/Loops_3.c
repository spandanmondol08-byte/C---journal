/*
Quick Quiz: Write a program to print natural numbers from 10 to 20 when initial loop
counter is initialized to 0.
*/

#include <stdio.h>

int main()
{
  int i = 0;
  int n = 10;
  while (i <= 10)
  {
    printf("%d\n", n);
    n = n + 1;
    i = i + 1;
  }

  return 0;
}