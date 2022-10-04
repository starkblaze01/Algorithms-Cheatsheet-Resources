#include <stdio.h>
#include <conio.h>

int currentbal,initialbal,withdraw,deposit,choice,i,pin;
float principal, t, rate, SI;
char transaction ='y';

int main()
{
    while (pin != 3579)
{
    printf("ENTER YOUR PIN NUMBER: ");
    scanf("%d", &pin);
    if (pin != 3579)
    printf("PLEASE ENTER VALID PASSWORD\n");
}
  
printf("Enter initial balance:\n");
scanf("%d",&initialbal);
do{
    printf("Select your choice:");
    printf("*********Welcome to ATM Service*********\n");
       printf("1. Check Balance\n");
       printf("2. Deposit Cash\n");
       printf("3. Withdraw Cash\n");
       printf("4. View previous transaction\n");
       printf("5. Calculate interest accrued in the account\n");
       printf("6. Exit the application\n");
       printf("Enter your choice: \n");
       scanf("%d", &choice);
  
switch(choice)
{
    case 1:
    printf("The current balance is Rs.%d", currentbal );
    break;
  
    case 2:
    printf("Enter the amount to deposit in the account: \n");
    scanf("%d", &deposit);
    currentbal = initialbal + deposit;
    break;
  
    case 3:
    printf("Enter the amount to withdraw from the account: \n");
    scanf("%d", &withdraw);
    currentbal = currentbal - withdraw;
    break;
  
    case 4:
    if(currentbal>initialbal)
    printf("The overall deposit is made of Rs. %d\n", currentbal - initialbal);
    else
    printf("The overall withdrawal is made of Rs. %d\n", initialbal - currentbal);
    break;
  
    case 5:
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the time period: ");
    scanf("%f", &t);
    printf("Enter the rate of interest: ");
    scanf("%f", &rate);
    SI = (principal * t * rate) / 100;
    printf("Simple Interest for Principal Amount %.2f is %.2f", principal, SI);
    break;
  
    case 6:
    printf("Exiting Program\n");
    break;
  
    default:
    printf("\n INVALID CHOICE");
}

printf("\n\n\n DO U WISH TO HAVE ANOTHER TRANSCATION?(y/n): ");
fflush(stdin);
scanf("%c", &transaction);
if (transaction == 'n'|| transaction == 'N')
i = 0;
} while (!i);

printf("\n\n THANKS FOR USING OUR ATM SERVICE");
}