/*
Write a program to create an array of 10 integers and store multiplication table of
a number entered by user in it and print.
*/

#include <stdio.h>

int main() {
  int mul[10];
  int n;
  printf("Enter the number whose multiplication table you want : ");
  scanf("%d",&n);
  for (int i = 0;i<10;i=i+1){
    mul[i]=n*(i+1);
  }
  for (int i = 0;i<10;i=i+1)
  {
    printf("%d X %d = %d\n",n,i+1,mul[i]);
  }
  return 0;
}