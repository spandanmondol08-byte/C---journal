// Write problem 5’s structure using ‘typedef’ keywords.

#include <stdio.h>
typedef struct complex
{
  int re;
  int im;
} cn;
void display(cn c)
{ 
  printf("The complex number is : %d + %d i\n", c.re, c.im);
}
int main()
{
  cn c[5];
  for (int i =0;i<5;i++)
  {
    printf("Enter the real part of complex number %d : ", i + 1);
    scanf("%d", &c[i].re);
    printf("Enter the imaginary part of complex number %d : ", i + 1);
    scanf("%d", &c[i].im);
    display(c[i]);
  }
  
  
  return 0;
}