#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> //for clearing screen
#include <unistd.h>  //for sleep
int i = 0, k = 0;
struct account
{
   char name[40];
   char lname[40];
   char password[30];
   int ac;
   int phone;
   float balance;
   int year, month, day;
   char address[50];
   char username[70];
};

int main()
{
   struct account c, b; // c is initial struct ko variable, b paxi baneko
   char filename[70], user[30], pword[30], phone[10];
   int choice, no, length = 0, m = 0; // no for case a to go back to menu
   float amount;
   char com = 'y';
   system("COLOR 80");
   printf("\n%20.s-------------------------------------------");
   printf("\n\n\n\n%20.s     WELCOME TO OUR ONLINE BANKING SYSTEM");
   printf("\n\n\n%20.s--------------------------------------------");
   printf("\n\n\nLoading");
   for (i = 0; i < 3; i++)
   {
      printf(".");
      sleep(1);
   }
   system("cls");
   FILE *fp;
   char option;
log:
   printf("\n%10.s ------------------------------------");
   printf("\n%10.s ~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~");
   printf("\n%10.s ------------------------------------");
   printf("\n\n%15.s a. Create an account");
   printf("\n%15.s b. Already a user?Sign in ");
   printf("\n%15.s c. Exit");
   fflush(stdin);
   printf("\n\n%15.s Enter your choice:  ");
   scanf("%c", &option);
   fflush(stdin);
   switch (option)
   {
   case 'a':
      system("cls");
      printf("\n%20.sKindly fill up all your information\n");
      fflush(stdin);
      printf("\nFirst name: ");
      gets(c.name);
      fflush(stdin);
      printf("\nLast name: ");
      gets(c.lname);
      fflush(stdin);
      printf("\nAccount Number: ");
      scanf("%d", &c.ac);
      fflush(stdin);
      printf("\nPhone Number:");
      scanf("%d", &c.phone);
      fflush(stdin);
      printf("\nDate of birth..\n");
      printf("Year: ");
      scanf("%d", &c.year);
      fflush(stdin);
      printf("\nMonth: ");
      scanf("%d", &c.month);
      fflush(stdin);
      printf("\nDay: ");
      scanf("%d", &c.day);
      fflush(stdin);
      printf("\nAddress: ");
      gets(c.address);
      fflush(stdin);
      printf("\n\nUsername: ");
      gets(c.username);
      fflush(stdin);
      printf("\nPassword should not exceed more than 8 characters!");
   back:
      printf("\nPassword: ");
      gets(c.password);
      fflush(stdin);
      for (i = 0; c.password[i] != '\0'; i++)
      {
         length++;
      }
      if (length > 8)
      {
         printf("More than 8 characters are not allowed");
         printf("\n PLEASE TRY AGAIN");
         length = 0;
         goto back;
      }
      c.balance = 0;
      strcpy(filename, c.username);
      fp = fopen(strcat(filename, ".txt"), "ab+");
      if (fwrite(&c, sizeof(c), 1, fp) != 0)
      {
         system("cls");
         printf("\n%15.sAccount successfully registered!");
         for (i = 0; i < 2; i++)
         {
            sleep(1);
            printf("!");
         }
      }
      else
      {
         printf("\nSomething went wrong");
      }
      fclose(fp);
   reset:
      printf("\n\n\n Press 1 to go back to main menu 0 to exit:");
      scanf("%d", &m);
      if (m == 1)
      {
         system("cls");
         fflush(stdin);
         goto log;
      }
      else
      {
         exit(0);
      }
      break;
   case 'b':
      system("cls");
   recheck:
      system("cls");
      fflush(stdin);
      printf("\n%15.s~LOGIN PAGE~\n");
      printf("\n%10.sEnter username: ");
      gets(user);
      fflush(stdin);
      printf("\n%10.sEnter password: ");
      gets(pword);
      fflush(stdin);
      strcpy(filename, user);
      fp = fopen(strcat(filename, ".txt"), "rb");
      if (fp == NULL)
      {
         printf("\nAccount not registered, complete your registration");
         for (i = 0; i < 3; i++)
         {
            printf("!");
            sleep(1);
            system("cls");
            goto log;
         }
      }
      else
      {
         fread(&c, sizeof(c), 1, fp);
         fclose(fp);
         if (!strcmp(pword, c.password))
         {
            printf("Login Sucess");
            for (i = 0; i < 3; i++)
            {
               printf("!");
               sleep(1);
            }
            while (com == 'y')
            {
            label:
               system("cls");
               printf("\n Welcome: %s %s!", c.name, c.lname);
               printf("\n\n");
               printf("\n%15.s* Press 1 for balance enquiry ");
               printf("\n%15.s* Press 2 to deposit an amount");
               printf("\n%15.s* Press 3 for Cash withdrawl");
               printf("\n%15.s* Press 4 for online transfer");
               printf("\n%15.s* Press 5 to view account information");
               printf("\n%15.s* Press 6 to exit");
               printf("\n\n\n%15.s Enter your choice:");
               scanf("%d", &choice);
               fflush(stdin);
               switch (choice)
               {
               case 1:
                  system("cls");
                  printf("%15.sBALANCE ENQUIRY SECTION");
                  printf("\n\n Dear %s, your current balance is %.2f", c.username, c.balance);
                  break;
               case 2:
                  system("cls");
                  printf("%15.sDEPOSIT SECTION");
                  printf("\n\nEnter the amount you want to deposit: ");
                  scanf("%f", &amount);
                  c.balance += amount;
                  fp = fopen(filename, "w");
                  fwrite(&c, sizeof(c), 1, fp);
                  if (fwrite != NULL)
                  {
                     printf("\nSuccessfully  deposited");
                  }
                  fclose(fp);
                  break;
               case 3:
                  system("cls");
                  printf("%15.sWITHDRAW SECTION");
                  printf("\n\nEnter the amount you want to withdraw: ");
                  scanf("%f", &amount);
                  if(c.balance<amount)
                  {
                  printf("\nInsufficient Balance");
 }
 else
 {
                  c.balance -= amount;
                  fp = fopen(filename, "w");
                  fwrite(&c, sizeof(c), 1, fp);
                  if (fwrite != NULL)
                  {
                     printf("\nSuccessfully withdrawn");
                  }
              }
                  fclose(fp);
                  break;
               case 4:

                  system("cls");
                  printf("%15.sONLINE MONEY TRANSFER SECTION");
                  printf("\n\nEnter the user name to transfer balance:");
                  scanf("%s", &user);
                  printf("\nEnter the amount you want to transfer: ");
                  scanf("%f", &amount);
                  strcpy(filename, user);
                  fp = fopen(strcat(filename, ".txt"), "r");
                  if (fp == NULL)
                  {
                     printf("\nThis username is not registered!");
                  }
                  else
                  {
                     fread(&b, sizeof(b), 1, fp);
                     fclose(fp);
                     if (amount > c.balance)
                     {
                        printf("\nYour balance is insufficient!!");
                     }
                     else
                     {
                        fp = fopen(filename, "w");
                        b.balance += amount;
                        fwrite(&b, sizeof(b), 1, fp);
                        fclose(fp);
                        if (fwrite != NULL)
                        {
                           printf("\nYou have successfully transfered Rs.%.2f to %s", amount, user);
                           strcpy(filename, c.username);
                           fp = fopen(strcat(filename, ".dat"), "w");
                           c.balance -= amount;
                           fwrite(&c, sizeof(c), 1, fp);
                           fclose(fp);
                        }
                     }
                  }
                  break;
               case 5:
                  system("cls");
                  printf("\n%10.sAccount Information");
                  fp = fopen("filename.txt", "r");
                  while (fread(&c, sizeof(c), 1, fp) == 1)
                     rewind(fp);
                  {
                     printf("\n\nFirst name: %s", c.name);
                     printf("\n\nLast name: %s", c.lname);
                     printf("\n\nAccount Number: %d", c.ac);
                     printf("\n\nPhone Number: %d", c.phone);
                     printf("\n\nDate of birth..");
                     printf("\n\nYear: %d", c.year);
                     printf("\n\nMonth: %d", c.month);
                     printf("\n\nDay: %d", c.day);
                     printf("\n\nAddress: %s", c.address);
                  }
                  fclose(fp);
                  break;
               case 6:
                 system("cls");
                 printf("Thankyou for your cooperation,Bye!");
                 for(i=0;i<3;i++)
                 {
                  printf("!");
                  sleep(1);
}
                  exit(0);
               default:
               {
                  printf("\nInvalid option!Please try again.");
                  sleep(2);
                  goto label;
               }
               }
               printf("\n\nDo you want to continue the transaction?");
               printf("\nIf yes press 'y' else print 'n':");
               scanf("%s", &com);
            }
         }
         else
         {
            printf("\nInvalid password!!");

            printf("Press 1 to try again 0 to exit:");
            scanf("%d", &k);
            if (k == 1)
            {
               goto recheck;
            }
            else if (k == 0)
            {
               exit(0);
            }
         }
      }

      break;
   case 'c':
      system("cls");
      printf("\n%20.s~~Bye~~");
      exit(0);
      break;

   default:
      printf("\nYou have entered wrong choice! Please try again.");
      sleep(3);
      system("cls");
      goto log;
   }
   return 0;
}

