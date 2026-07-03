/*
Write a program to change the value of a variable to ten times of its current
value.
*/

#include <stdio.h>

int main() {
  int i;
  printf("Enter the number whose 10 times you want : ");
  scanf("%d",&i);
  int * j = &i;
  *j=10**j;
  printf("The value is : %d",i);

  return 0;
}