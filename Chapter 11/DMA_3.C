// calloc()

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 5;
  int *ptr;
  ptr = (int*) calloc(n,sizeof(int));
  for (int i=0 ; i<5;i++)
  {
    printf("%d\n",ptr[i]);
  }
  
  return 0;
}