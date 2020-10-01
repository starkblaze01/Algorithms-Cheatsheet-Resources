// Algorithm to reverse the string(without space)
// Default max size of the string is set to 20.
#include <stdio.h>
void srev(char *);
int main()
{
    char s[20];
    printf("Enter the string=");
    scanf("%s", s);
    srev(s);
    printf("Reverse string=");
    printf("%s", s);
    return 0;
}
void srev(char *s1)
{
    int len = 0, i;
    char temp;
    while (*(s1 + len) != '\0')
        len++;
    for (i = 0; i < len / 2; i++)
    {
        temp = *(s1 + i);
        *(s1 + i) = *(s1 + len - 1 - i);
        *(s1 + len - 1 - i) = temp;
    }
}
