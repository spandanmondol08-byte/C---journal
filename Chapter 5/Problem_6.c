// Write a recursive function to calculate the sum of first ‘n’ natural numbers.

#include <stdio.h>

int sum(int n)
{
  if (n==0)
  {
    return 0;
  }
  return sum(n-1)+n;
}

int main() {
  int n;
  printf("Enter the term : ");
  scanf("%d",&n);
  int y = sum(n);
  printf("The sum of %d terms of the series is : %d",n,y);

  return 0;
}