#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct user_accounts
{
  char account_name[30];
  char password[30];
  int account_number;
  int account_balance;
}uac;


void create_account(uac users[3],int n)
{
  FILE * ptr;
  ptr=fopen("Bank_Info.txt","a");
  printf("Enter the account Name : ");
  getchar();
  fgets(users->account_name,30,stdin);
  users->account_name[strcspn(users->account_name,"\n")]='\0';
  fputs(users->account_name,ptr);
  printf("Enter your password : ");
  fclose(ptr);
 
}

int main() {
  uac users[3];
    int n=0;
    int ch;
  while (1)
  {
    
    printf("1) Create Account\n");
    printf("2) Withdraw Money\n");
    printf("3) Deposit Money\n");
    printf("4) EXIT!!!\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    sleep(1);
    if (ch==1)
    {
      if(n==3)
      {
        printf("Exceeded maximum limit for number of registration\n");
      }
      else{
        create_account(users,n);
        n++;
      }
      
    }
    else if (ch==2)
    {

    }
    else if (ch==3)
    {

    }
    else if (ch==4)
    {
      printf("EXITING !!!\n");
      break;
    }
    else
    {
      printf("Enter valid choice !!!\n");
      sleep(1);
    }
  }
  

  return 0;
}