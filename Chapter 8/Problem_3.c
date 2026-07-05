/* Write a function slice() to slice a string. It should change the original string such
that it is now the sliced string. Take ‘m’ and ‘n’ as the start and ending position
for slice. */

#include <stdio.h>
char nstr[30];
void slice(char str[30],int m , int n)
{
  for (int j = m ; j<=n;j++)
  {
    nstr[j-m]=str[j];
  }
  nstr[n-m+1]='\0';
}

int main() {
  char s[30];
  printf("Enter the string : ");
  gets(s);
  int m,n;
  printf("Enter the starting index : ");
  scanf("%d",&m);
  printf("Enter the ending index : ");
  scanf("%d",&n);
  slice(s,m,n);
  printf("The sliced string from index %d to index %d is : %s",m,n,nstr);

  return 0;
}