/*
 Create an array of size 3 x 10 containing multiplication tables of three numbers entered by user respectively.
*/

#include <stdio.h>

int main() {
  int a[3][10];
  int x,y,z;
  printf("Enter the first number whose multiplication table you want : ");
  scanf("%d",&x);
  printf("Enter the second number whose multiplication table you want : ");
  scanf("%d",&y);
  printf("Enter the third number whose multiplication table you want : ");
  scanf("%d",&z);

  for (int i = 0; i < 10; i++) {
    a[0][i] = x * (i + 1);
    a[1][i] = y * (i + 1);
    a[2][i] = z * (i + 1);
  }

  printf("Multiplication table of %d:\n", x);
  for (int i = 0; i < 10; i++) {
    printf("%d X %d = %d\n", x, i + 1, a[0][i]);
  }
  printf("\n");

  printf("Multiplication table of %d:\n", y);
  for (int i = 0; i < 10; i++) {
    printf("%d X %d = %d\n", y, i + 1, a[1][i]);
  }
  printf("\n");

  printf("Multiplication table of %d:\n", z);
  for (int i = 0; i < 10; i++) {
    printf("%d X %d = %d\n", z, i + 1, a[2][i]);
  }
  printf("\n");

  return 0;
}