//Area of circle

#include <stdio.h>

int main() {
  int r;
  printf("Enter the radius of the circle: ");
  scanf("%d", &r);
  float area = 3.14*r*r;
  printf("Area of the circle is : %f", area);

  return 0;
}