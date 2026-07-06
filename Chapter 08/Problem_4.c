// Write your own version of strcpy function from <string.h>

#include <stdio.h>
void scopy(char *ptr,char s[])
{
  for (int i= 0 ; s[i]!='\0';i++)
  {
    *(ptr)=s[i];
    ptr++;
  }
  *ptr='\0';
}

int main() {
  char src[30];
  printf("Enter the source string : ");
  gets(src);
  char t[30];
  scopy(t,src);
  printf("%s",t);


  return 0;
}