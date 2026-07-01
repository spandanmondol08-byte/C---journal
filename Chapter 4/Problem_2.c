//Write a program to print multiplication table of a given number n

#include <stdio.h>

int main() {
  int n;
  printf("Enter the Number whose multiplication table you want : ");
  scanf("%d",&n);
  printf("----------------------------------MULTIPLICATION TABLE OF %d-----------------------------------\n",n);
  for (int i = 1 ; i<11 ; i = i+1)
  {
    int x = i*n;
    printf("%d X %d = %d\n",n,i,x);
  }

  return 0;
}