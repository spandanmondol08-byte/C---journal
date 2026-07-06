#include <stdio.h>
#include <string.h>
struct employee
{
  int code;
  int salary;
  char name[30];
};

int main() {
  struct employee e[10];
  for (int i = 0 ; i < 10 ; i++)
  {

    printf("Enter the code of employee %d : ",i+1);
    scanf("%d",&e[i].code);
    printf("Enter the salary of employee %d : ",i+1);
    scanf("%d",&e[i].salary);
    printf("Enter the name of employee %d : ",i+1);
    scanf("%s",e[i].name);
    e[i].name[strlen(e[i].name)] ='\0';
  }
  
  return 0;
}