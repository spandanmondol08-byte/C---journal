// Check if character entered is in Upercase or Lowercase using ASCII values

#include <stdio.h>

int main()
{
  char ch;
  printf("Enter a character in either uppercase or lowercase: ");
  scanf("%c", &ch);
  int ach;
  ach = (int)ch;
  if (ach > 97)
  {
    printf("The character entered is in lowercase\n");
  }
  else
  {
    printf("The character entered is in uppercase\n");
  }
  return 0;
}