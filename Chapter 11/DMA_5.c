// relloc()

#include <stdio.h>
#include <stdlib.h>

int main() {
  int f=5;
  int *ptr;
  ptr=(int*) malloc(f*sizeof(int));
  
  for (int i=0 ; i<5;i++)
  {
    printf("%d\n",ptr[i]);
  }
  printf("New allocation!!!\n");
  ptr = realloc(ptr,10*sizeof(int));
  
  for (int i=0 ; i<10;i++)
  {
    printf("%d\n",ptr[i]);
  }
  return 0;
}