#include <stdio.h>
#include <string.h>

typedef struct User_List
{
  char username[30];
  char password[30];
}user_list;

void registration(user_list users[3],int uno)
{
  if (uno==4)
  {
    printf("Exceeded maximum limit for number of registration\n");
    return;
  }
  else
  {
    getchar();
    printf("Enter the username : ");
    fgets(users[uno-1].username, 30, stdin);
    users[uno-1].username[strcspn(users[uno-1].username,"\n")]='\0';
    printf("Enter the password : ");
    fgets(users[uno-1].password, 30, stdin);
    users[uno-1].password[strcspn(users[uno-1].password,"\n")]='\0';
  }
}

void login(user_list users[3],int uno)
{
  int found;
  char login_un[30];
  char login_pw[30];
  getchar();
  printf("Enter the username : ");
  fgets(login_un, 30, stdin);
  login_un[strcspn(login_un,"\n")]='\0';
  for (int i =0 ; i = uno;i++)
  {
    if (strcmp(login_un,users[i].username)==0)
    {
      printf("Enter the password : ");
      fgets(login_pw, 30, stdin);
      login_pw[strcspn(login_pw,"\n")]='\0';
      if (strcmp(login_pw,users[i].password)==0)
      {
        printf("You are logged in successfully !!!\n");
        return;
      }
      else
      {
        printf("Invalid Password\n");
        return;
      }  
    }
    else
    {
      found = 1;
    }
  }
  if (found==1)
  {
    printf("Username not found !!!!\n");
  }
  
}

int main() {
  printf("-----------------------------WELCOME------------------------------\n");
  int uno = 0;
  user_list users[3];

  while (1)
  {
    int ch ;
    printf("Enter 1 to REGISTER new user\n");
    printf("Enter 2 to LOGIN existing user\n");
    printf("Enter 3 to EXIT!!\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    if (ch==1)
    {
      uno++;
      registration(users , uno);
      printf("Successfully Registered !!!\n");
      
    }
    else if (ch == 2)
    {
      login(users,uno);
    }
    else if (ch==3)
    {
      printf("EXITING!!!!!\n");
      break;
    }
    else
    {
      printf("Enter a valid choice !!!\n");
    }
  }
  

  return 0;
}