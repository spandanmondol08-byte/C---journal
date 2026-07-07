// malloc() :

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n ;
  int *ptr ;
  scanf("%d",n);
  ptr= (int*) malloc(n * sizeof(int));
  ptr[0]=56;
  ptr[1]=34;
  printf("%d , %d",ptr[0],ptr[1]);
  return 0;
}