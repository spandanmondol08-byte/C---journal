// Create a structure representing a bank account of a customer.

#include <stdio.h>
#include <string.h>

typedef struct bank
{
  int account_number;
  char holder_name[30];
  char ifsc_code[30];
  float balance;
} bdet;

int main() {
  bdet c1;
  c1.account_number=72809437;
  strcpy(c1.holder_name,"Spandan Mondol");
  strcpy(c1.ifsc_code,"ISBN8796");
  c1.balance=2349875.30;
  printf("Account Number : %d\n", c1.account_number);
  printf("Holder Name    : %s\n", c1.holder_name);
  printf("IFSC Code      : %s\n", c1.ifsc_code);
  printf("Balance        : %.2f\n", c1.balance);

  return 0;
}