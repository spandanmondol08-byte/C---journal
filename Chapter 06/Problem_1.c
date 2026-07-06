/* 
Write a program to print the address of a variable. Use this address to get the
value of the variable 
*/

#include <stdio.h>

int main() {
  int i = 435;
  int *j=&i;
  printf("The address of i is : %p\n", j);
  printf("The value stored is : %d\n", *j);

  return 0;
}