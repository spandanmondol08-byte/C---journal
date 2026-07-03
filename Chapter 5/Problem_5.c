// Write a program using recursion to calculate nth element of Fibonacci series.

#include <stdio.h>

int fibonacci(int n)
{
  if (n==1) 
  {
    return 0;
  }                           // BASE CONDITION
  else if (n==2)
  {
    return 1;
  }
  int x = fibonacci(n-1)+fibonacci(n-2) ; 
  return x ;
}

int main() {
  int n ;
  printf("Enter the term you want : ");
  scanf("%d",&n);
  int y = fibonacci(n);
  printf("The %d th term is : %d",n,y);

  return 0;
}