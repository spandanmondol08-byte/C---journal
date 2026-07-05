// Write a program to count the occurrence of a given character in a string.

#include <stdio.h>

int main() {
  char str[30];
  printf("Enter the string : ");
  gets(str);
  char ch;
  printf("Enter the character : ");
  scanf("%c",&ch);
  int c=0;
  for (int i = 0 ; str[i]!='\0';i++)
  {
    if (str[i]==ch)
    {
      c++;
    }
  }
  printf("The character %c occurs %d times in the string",ch,c);
  return 0;
}
