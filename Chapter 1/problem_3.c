//Volume of a cylinder

#include <stdio.h>

int main() {
  int r,h;
  printf("Enter the radius of the cylinder: ");
  scanf("%d", &r);
  printf("Enter the height of the cylinder: ");
  scanf("%d", &h);
  float volume = 3.14*r*r*h;
  printf("Volume of the cylinder is : %f", volume);

  return 0;
}