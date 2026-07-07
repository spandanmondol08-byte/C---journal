// Solve problem 1 using calloc()

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n =6 ;
  int *ptr ;
  ptr= (int*) calloc(n , sizeof(int));
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