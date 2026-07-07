// Create an array dynamically capable of storing 5 integers. Now use realloc so
// that it can now store 10 integers

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 5 ;
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
  printf("New Size !!\n");
  ptr =realloc(ptr,10*sizeof(int));
  ptr[0]=56;
  ptr[1]=34;
  ptr[2]=65;
  ptr[3]=55;
  ptr[4]=99;
  ptr[5]=96;
  ptr[6]=31;
  ptr[7]=60;
  ptr[8]=15;
  ptr[9]=9;
  for (int i=0;i<10;i++){
    printf("%d\n",ptr[i]);
  }
  return 0;
}