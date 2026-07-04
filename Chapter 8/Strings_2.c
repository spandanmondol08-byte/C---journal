#include <stdio.h>

int main()
{
  char s[30];
  gets(s);
  printf("%s", s);
  printf("Done\n"); // Printed on the same line
  puts(s);
  printf("Done"); // Printed on the next line

  return 0;
}