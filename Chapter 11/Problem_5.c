// Create an array of multiplication table of 7 upto 10 (7 x 10 = 70). Use realloc to
// make it store 15 number (from 7 x 1 to 7 x 15).

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 10 ;
  int *ptr ;
  ptr= (int*) malloc(n * sizeof(int));
  for (int i=0;i<10;i++){
    ptr[i]=(i+1)*7;
  }
  
  for (int i=0;i<10;i++){
    printf("7 X %d = %d\n",i+1,ptr[i]);
  }
  printf("New Size !!\n");
  ptr =realloc(ptr,15*sizeof(int));
  for (int i=5;i<15;i++){
    ptr[i]=(i+1)*7;
  }
  for (int i=0;i<15;i++){
    printf("7 X %d = %d\n",i+1,ptr[i]);
  }
  return 0;
}