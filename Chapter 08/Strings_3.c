#include <stdio.h>

int main() {
  char s[] = "abc";
  char *ptr=s;
  *ptr='a';
  *(ptr+1)='x';
  *(ptr+2)='x';

  printf("%s",s);

  return 0;
}