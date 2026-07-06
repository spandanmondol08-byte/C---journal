// Change Function call by value

#include <stdio.h>

int change1(int a1)
{
  a1 = 6;
  return a1;
}

// Change Function call by reference

int change2(int *a2)
{
  *a2 = 6;
  return *a2;
}


int main()
{
  int x1 = 1;
  int y1 = change1(x1);
  printf("Value of x in case 1 : %d\n", x1);

  int x2 = 1;
  int y2 = change2(&x2);
  printf("Value of x in case 2 : %d\n", x2);

  return 0;
}