int sum(int, int); // function prototype (used if we not define function in the start)

int sum(int a, int b) // function defination
{
  int s = a + b;
  return s;
}
#include <stdio.h>

int main()
{
  int x;
  printf("Enter a Number : ");
  scanf("%d", &x);
  int y;
  printf("Enter a Number : ");
  scanf("%d", &y);
  int c = sum(x, y);
  printf("The sum is : %d", c);

  return 0;
}