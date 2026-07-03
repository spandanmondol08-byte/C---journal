#include <stdio.h>

void swap(int* a,int* b)
{
  int z;
  z=*a;
  *a=*b;
  *b=z;

} 

int main() {
  int x,y;
  printf("Enter first number to swap : ");
  scanf("%d",&x);
  printf("Enter second number to swap : ");
  scanf("%d",&y);
  swap(&x,&y);
  printf("The value of x : %d\n",x);
  printf("The value of y : %d",y);

  return 0;
}