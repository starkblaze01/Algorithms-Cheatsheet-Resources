/*bubble sort*/
#include <stdio.h>

void bubbleSort(int[], int);
int main()
{
    int a[100], i, n;

    printf("Enter size of the  array : ");
    scanf("%d", &n);
    printf("Enter elements in array : \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bubbleSort(a, n);

    printf("The sorted Array : \n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
    return 0;
}

void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
    }
}