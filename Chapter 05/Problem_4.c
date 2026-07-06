// Write a function to calculate force of attraction on a body of mass ‘m’ exerted by
// earth. Consider g = 9.8m/s2

#include <stdio.h>

float force(float m)
{
  const float g = 9.8;
  float f = m * g;
  return f;
}

int main()
{
  float m;
  printf("Enter the mass of the body : ");
  scanf("%f", &m);
  float x = force(m);
  printf("The force on the body of %.2f KG is : %.2f m/s^2", m, x);

  return 0;
}