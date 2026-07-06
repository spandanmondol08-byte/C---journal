// Write a program to modify a file containing an integer to double its value.

#include <stdio.h>

int main() {
  FILE *ptr1 ,*ptr2;
  ptr1=fopen("fp6.txt","r");
  
  int num;
  fscanf(ptr1,"%d",&num);
  fclose(ptr1);
  ptr2=fopen("fp6.txt","w");
  int n=num*2;
  fprintf(ptr2,"%d",n);
  fclose(ptr2);
  printf("Done!!");
  return 0;
}
