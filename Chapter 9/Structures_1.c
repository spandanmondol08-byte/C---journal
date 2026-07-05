#include <stdio.h>
#include <string.h>

int main() {
  struct employee
  {
    int code;
    float salary;
    char name[30];
  };

  struct employee e1,e2,e3;
  e1.code=1;
  e1.salary=54000;
  strcpy(e1.name,"Spandan");
  printf("%d , %.2f , %s\n",e1.code,e1.salary,e1.name);
  e2.code=2;
  e2.salary=58000;
  strcpy(e2.name,"Joydeep");
  printf("%d , %.2f , %s\n",e2.code,e2.salary,e2.name);
  e3.code=3;
  e3.salary=34000;
  strcpy(e3.name,"Sanhit");
  printf("%d , %.2f , %s\n",e3.code,e3.salary,e3.name);
 
  return 0;
}