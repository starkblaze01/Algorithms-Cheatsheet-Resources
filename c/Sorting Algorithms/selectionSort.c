/*selection sort*/
#include <stdio.h>

void selectionSort(int[], int);
int main()
{
    int a[100], i, n;

    printf("Enter size of the  array : ");
    scanf("%d", &n);
    printf("Enter elements in array : \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    selectionSort(a, n);

    printf("The sorted Array : \n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
    return 0;
}

void selectionSort(int a[], int n)
{
    int i, j, temp, min;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        if (min != i)
        {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}