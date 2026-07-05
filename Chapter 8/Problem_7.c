// Write a program to check whether a given character is present in a string or not.

#include <stdio.h>

int main() {
  char str[30];
  printf("Enter the string : ");
  gets(str);
  char ch;
  printf("Enter the character : ");
  scanf("%c",&ch);
  for (int i = 0 ; str[i]!='\0';i++)
  {
    if (str[i]==ch)
    {
      printf("Yes the character %c is present in the string",ch);
    }
    else
    {
      printf("No the character %c is not present in the string",ch);
    }
  }

  return 0;
}
