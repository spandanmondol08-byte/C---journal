#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

typedef struct user_accounts
{
  int id;
  char account_name_f[30];
  char account_name_l[30];
  char password[30];
  int account_number;
  int account_balance;
  int trans;
} uac;

void encrypter(uac users[30], int n)
{
  int shift = (users[n].account_number % 9) + 3;
  for (int i = 0; users[n].password[i] != '\0'; i++)
  {
    users[n].password[i] = users[n].password[i] + shift;
  }
}

void decrypter(uac users[30], int n)
{
  int shift = (users[n].account_number % 9) + 3;
  for (int i = 0; users[n].password[i] != '\0'; i++)
  {
    users[n].password[i] = users[n].password[i] - shift;
  }
}

void inputPassword(char password[])
{
  int i = 0;
  char ch;
  while ((ch = getch()) != '\r') // Enter key
  {
    if (ch == '\b' && i > 0) // Backspace
    {
      i--;
      printf("\b \b");
    }
    else if (ch != '\b' && i < 29)
    {
      password[i++] = ch;
      printf("*");
    }
  }
  password[i] = '\0';
  printf("\n");
}

void create_account(uac users[30], int n)
{
  while (1)
  {
    int a = 676900000;
    int rn = rand() % 90000 + 10000;
    users[n].account_number = a + rn;
    int ok = 0;
    for (int i = 0; i < n; i++)
    {
      if (users[i].account_number == users[n].account_number)
      {
        ok = ok + 0;
      }
      else
      {
        ok++;
      }
    }
    if (ok == n)
    {
      break;
    }
  }
  users[n].account_balance = 0;
  users[n].trans = 0;
  FILE *ptr;
  ptr = fopen("Bank_Info.txt", "a");
  users[n].id = n + 1;
  fprintf(ptr, "%d\n", users[n].id);
  printf("Enter the first name of account holder : ");
  getchar();
  fgets(users[n].account_name_f, 30, stdin);
  users[n].account_name_f[strcspn(users[n].account_name_f, "\n")] = '\0';
  fprintf(ptr, "First Name: %s\n", users[n].account_name_f);
  printf("Enter the last name of account holder : ");
  fgets(users[n].account_name_l, 30, stdin);
  users[n].account_name_l[strcspn(users[n].account_name_l, "\n")] = '\0';
  fprintf(ptr, "Last Name: %s\n", users[n].account_name_l);
  printf("Enter your password : ");
  inputPassword(users[n].password);
  encrypter(users, n);
  fprintf(ptr, "Password: %s\n", users[n].password);
  fprintf(ptr, "Account Number: %d\n", users[n].account_number);
  fprintf(ptr, "Account Balance: %d\n", users[n].account_balance);
  fprintf(ptr, "Recent Transaction: %d\n", users[n].trans);
  fprintf(ptr, "---------------------------------\n");
  fprintf(ptr, "\n");
  fclose(ptr);
  printf("\nAccount created successfully!\n\n");
  printf("---------------------------------\n");
  printf("Account Holder Name : %s %s\n", users[n].account_name_f, users[n].account_name_l);
  printf("Account Number : %d\n", users[n].account_number);
  printf("Balance : %d\n", users[n].account_balance);
  printf("---------------------------------\n");
  sleep(2);
}

void saveUsers(uac users[30], int n)
{
  FILE *fp = fopen("Bank_Info.txt", "w");

  for (int i = 0; i < n; i++)
  {
    encrypter(users, i);

    fprintf(fp, "%d\n", users[i].id);
    fprintf(fp, "First Name: %s\n", users[i].account_name_f);
    fprintf(fp, "Last Name: %s\n", users[i].account_name_l);
    fprintf(fp, "Password: %s\n", users[i].password);
    fprintf(fp, "Account Number: %d\n", users[i].account_number);
    fprintf(fp, "Account Balance: %d\n", users[i].account_balance);
    fprintf(fp, "Recent Transaction: %d\n", users[i].trans);
    fprintf(fp, "---------------------------------\n\n");

    decrypter(users, i);
  }

  fclose(fp);
}

int login(uac users[30], int n)
{
  while (1)
  {
    int account_no;
    char password[30];

    printf("Enter your account number : ");
    scanf("%d", &account_no);

    int found = 0;

    for (int i = 0; i < n; i++)
    {
      if (account_no == users[i].account_number)
      {
        found = 1;

        printf("Enter the password : ");
        inputPassword(password);

        if (strcmp(password, users[i].password) == 0)
        {
          printf("Login Successful!\n");
          printf("Welcome %s!\n", users[i].account_name_f);
          sleep(2);
          return i; 
        }
        else
        {
          printf("Incorrect Password!\n");
          break;
        }
      }
    }

    if (!found)
    {
      printf("Account number not found!!!!\n");
      sleep(1);
    }

    int choice;

    printf("\n1) Try Again\n");
    printf("2) Main Menu\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
      continue;
    }
    else
    {
      return -1;
    }
  }
}

void deposit(uac users[30], int n)
{
  int z = login(users, n);
  if (z == -1)
  {
    sleep(2);
    return;
  }
  else
  {
    int inc;
    printf("Enter the amount of money to deposit : ");
    scanf("%d", &inc);
    users[z].account_balance = inc + users[z].account_balance;
    sleep(1);
    users[z].trans = inc;
    printf("Your current balance : %d\n", users[z].account_balance);
    saveUsers(users, n);
    sleep(2);
  }
}

void withdraw(uac users[30], int n)
{
  int z = login(users, n);
  if (z == -1)
  {
    return;
  }
  if (users[z].account_balance == 0)
  {
    printf("Not sufficient balance!!!!");
    sleep(2);
    return;
  }
  else
  {
    if (z == -1)
    {
      sleep(2);
      return;
    }
    else
    {
      int dec;
      printf("Enter the amount of money to withdraw : ");
      scanf("%d", &dec);
      if (dec > users[z].account_balance)
      {
        printf("Not sufficient money !!!!\n");
        sleep(2);
        return;
      }
      users[z].account_balance = users[z].account_balance - dec;
      sleep(1);
      users[z].trans = dec * -1;
      printf("Your current balance : %d\n", users[z].account_balance);
      saveUsers(users, n);
      sleep(2);
    }
  }
}

void check(uac users[30], int n)
{
  int z = login(users, n);
  if (z == -1)
  {
    sleep(2);
    return;
  }
  else
  {
    printf("---------------------------------\n");
    printf("           YOUR DETAILS          \n");
    printf("---------------------------------\n");
    printf("Account Holder Name : %s %s\n", users[z].account_name_f, users[z].account_name_l);
    printf("Account Number : %d\n", users[z].account_number);
    printf("Balance: %d\n", users[z].account_balance);
    printf("Recent Transaction: %d\n", users[z].trans);
    printf("---------------------------------\n");
    
    printf("Enter any key to exit : ");
    char c;
    getchar();
    scanf("%c", &c);
  }
}

// MAIN

int main()
{
  srand(time(NULL));
  uac users[30];
  int n;
  FILE *ptr1;
  ptr1 = fopen("userno.txt", "r");
  fscanf(ptr1, "%d", &n);
  fclose(ptr1);
  FILE *ptr3;
  ptr3 = fopen("Bank_Info.txt", "r");
  for (int i = 0; i < n; i++)
  {
    fscanf(ptr3, "%d\nFirst Name: %s\nLast Name: %s\nPassword: %s\nAccount Number: %d\nAccount Balance: %d\nRecent Transaction: %d\n---------------------------------\n\n", &users[i].id, users[i].account_name_f, users[i].account_name_l, users[i].password, &users[i].account_number, &users[i].account_balance, &users[i].trans);
    decrypter(users, i);
  }
  fclose(ptr3);
  int ch;
  while (1)
  {
    printf("---------------------------------\n");
    printf("          BANKING SYSTEM         \n");
    printf("---------------------------------\n");
    printf("1) Create Account\n");
    printf("2) Withdraw Money\n");
    printf("3) Deposit Money\n");
    printf("4) Check Balance\n");
    printf("5) EXIT!!!\n");
    printf("---------------------------------\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    sleep(1);

    if (ch == 1)
    {
      if (n == 30)
      {
        printf("Exceeded maximum limit for number of registration\n");
      }
      else
      {
        create_account(users, n);
        n++;
        FILE *ptr2;
        ptr2 = fopen("userno.txt", "w");
        fprintf(ptr2, "%d", n);
        fclose(ptr2);
      }
    }
    else if (ch == 2)
    {
      withdraw(users, n);
    }
    else if (ch == 3)
    {
      deposit(users, n);
    }
    else if (ch == 5)
    {
      printf("EXITING !!!\n");
      sleep(1);
      break;
    }
    else if (ch == 4)
    {
      check(users, n);
    }
    else
    {
      printf("Enter valid choice !!!\n");
      sleep(1);
    }
  }
  return 0;
}