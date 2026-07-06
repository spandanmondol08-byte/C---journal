// Write a program to generate multiplication table of a given number in text
// format. Make sure that the file is readable and well formatted.

#include <stdio.h>

int main() {
  FILE *ptr;
  ptr=fopen("fp2.txt","w");
  int n ;
  printf("Enter the number whose multiplication table you want : ");
  scanf("%d",&n);
  for (int i = 1; i<=10;i++)
  {
    int mul =n*i;
    fprintf(ptr,"%d X %d = %d\n",n,i,mul);
  }
  fclose(ptr);
  return 0;
}