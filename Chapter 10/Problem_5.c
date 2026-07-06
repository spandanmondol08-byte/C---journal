/* Take name and salary of two employees as input from the user and write them to
a text file in the following format:
i. Name1, 3300
ii. Name2, 7700 */

#include <stdio.h>

int main() {
  FILE *ptr;
  ptr=fopen("fp5.txt","w");
  for (int i = 1 ; i<=2;i++)
  {
    int salary;
    char name[30];
    printf("Enter the name of employee %d : ",i);
    gets(name);
    printf("Enter the salary of employee %d : ",i);
    scanf("%d",&salary);
    getchar();
    fprintf(ptr,"%d) %s , %d\n",i,name,salary);
  }
  fclose(ptr);
  printf("Done!!");
  return 0;
}