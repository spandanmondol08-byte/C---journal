// Write a program to read a text file character by character and write its content
// twice in separate file.

#include <stdio.h>
#include <string.h>
int main() {
  FILE *ptr1 ,*ptr2;
  ptr1=fopen("fp3.txt","r");
  ptr2=fopen("fp4.txt","w");
  while (1)
  {
    char x=fgetc(ptr1);
    if(x==EOF)
    {
      break;
    }
    else{
      fputc(x,ptr2);
    }
  }
  rewind(ptr1);
  while (1)
  {
    char x=fgetc(ptr1);
    if(x==EOF)
    {
      break;
    }
    else{
      fputc(x,ptr2);
    }
  }
  
  fclose(ptr1);
  fclose(ptr2);
  printf("Work Done !!!!!");

  return 0;
}