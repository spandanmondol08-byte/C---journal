#include <stdio.h>
#include <string.h>

int main()
{
  // strlen() :

  char str[] = "Spandan";
  int len = strlen(str);
  printf("The lenght of string is : %d\n", len);

  // strcpy(target,source) :
  char s[] = "Spandan";

  char t[30];
  strcpy(t, s);
  printf("The copied string is : %s\n", t);

  // strcat() :

  char s1[] = "Spandan ";
  char s2[] = "Mondol";
  strcat(s1, s2);
  printf("The catenated string is : %s\n", s1);

  // strcmp() :
  
  printf("%d\n", strcmp("dark", "joke"));
  printf("%d\n", strcmp("joke", "dark"));
  printf("%d\n", strcmp("joke", "joke"));

  return 0;
}