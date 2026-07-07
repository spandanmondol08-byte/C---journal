// Write a program to create a dynamic array of 5 floats using malloc()

#include <stdio.h>
#include <stdlib.h>

int main() {
  float f=5;
  float *ptr;
  ptr=(float*) malloc(f*sizeof(float));
  ptr[0]=45.6;
  ptr[1]=46.6;
  ptr[2]=556.6;
  ptr[3]=454.64;
  ptr[4]=445.6;
  for (int i=0 ; i<5;i++)
  {
    printf("%.2f\n",ptr[i]);
  }
  return 0;
}