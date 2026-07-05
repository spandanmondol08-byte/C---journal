#include <stdio.h>
#include <string.h>

  typedef struct employee
  {
    int code;
    float salary;
    char name[30];
  } emp;
int main() {
  emp e1,e2,e3;
  e1.code=1;
  e1.salary=54000;
  strcpy(e1.name,"Spandan");
  printf("%d , %.2f , %s\n",e1.code,e1.salary,e1.name);
  emp *ptr=&e1;
  
  return 0;
}