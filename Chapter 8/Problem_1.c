// Write a program to take string as an input from the user using %c and %s confirm
// that the strings are equal.

#include <stdio.h>
#include <string.h>

int main() {
  char a[6];
  printf("Enter the string : ");
  scanf("%s",a);
  printf("The string : %s\n",a);
  char b[6];
  for (int i = 0; i < 5; i++)
  {
    printf("Enter the character : ");
    scanf(" %c",&b[i]);
   
  }
  b[5]='\0';
  printf("Are they equal : %d",strcmp(a,b));
  return 0;
}