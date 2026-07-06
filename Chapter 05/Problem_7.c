/* Write a program using function to print the following pattern (first n lines)

*
* * *
* * * * *                       

*/

#include <stdio.h>

int main() {
  int n ;
  printf("Enter number of lines : ");
  scanf("%d",&n);
  char x ='*';
  for (int i=1 ; i <= n ; i =i+1)
  {
    int y = 1+(i-1)*2;
    for (int j=1; j <= y;j=j+1)
    {
      printf("%c",x);
    }
    printf("\n");
  }

  return 0;
}