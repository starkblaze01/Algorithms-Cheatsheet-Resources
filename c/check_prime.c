#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    printf("Enter a number\n");
    scanf("%d" , &n);

    for (int i = 2; i< sqrt(n); i++)
    {
        if (n % i == 0)
        {
            printf("NOT PRIME NUMBER\n");
            break;
        }
        else
        {
            printf("PRIME NUMBER!\n");
            break;
        }
    }
    if(n<=1)
        {
            printf("Not Prime Number\n");
        }
    else if(n == 2 || n == 3)
        {
            printf("Prime Number\n");
        }
    return 0;
}
