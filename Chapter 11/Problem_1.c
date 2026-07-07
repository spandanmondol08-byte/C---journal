// Write a program to dynamically create an array of size 6 capable of storing 6
// integers.

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n =6 ;
  int *ptr ;
  ptr= (int*) malloc(n * sizeof(int));
  ptr[0]=56;
  ptr[1]=34;
  ptr[2]=65;
  ptr[3]=55;
  ptr[4]=99;
  for (int i=0;i<5;i++){
    printf("%d\n",ptr[i]);
  }
  
  return 0;
}