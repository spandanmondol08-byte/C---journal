// Write a program to illustrate the use of arrow operator → in C.

#include <stdio.h>
struct employee
{
  int code;
  int salary;
  char name[30];
};


int main() {
  struct employee e1;
  e1.code=54;
  struct employee *ptr=&e1;
  printf("The code of e1 is : %d",ptr -> code);
  return 0;
}