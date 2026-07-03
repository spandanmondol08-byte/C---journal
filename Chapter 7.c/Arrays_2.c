#include <stdio.h>

int main()
{
  int n;
  printf("Enter number of students : ");
  scanf("%d", &n);
  int mark[n];
  for (int i = 0; i < n; i = i + 1)
  {
    printf("Enter the marks of student %d : ", i + 1);
    scanf("%d", &mark[i]);
  }
  printf("Marks stored successfully !!!!!");

  return 0;
}