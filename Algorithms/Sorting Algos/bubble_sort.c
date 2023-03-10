#include <stdio.h>
#define MAX 5

// Function Prototype --->
void bubble_sort(int arr[]);
void display(int arr[]);

int main()
{
    int arr[MAX];
    int i = 0;
    printf("\nEnter elements of array ---> \n");
    while (i < MAX)
    {
        scanf("%d", &arr[i]);
        i++;
    }
    bubble_sort(arr);
    display(arr);
    return 0;
}

void display(int arr[])
{
    int i = 0;
    while (i < MAX)
        printf(" %d ", arr[i++]);
}

void bubble_sort(int arr[])
{
    for (int i = 0; i <= MAX; i++)
    {
        for (int j = 0; j <= (MAX - i - 1); j++)
        {
            if (arr[j] >= arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
