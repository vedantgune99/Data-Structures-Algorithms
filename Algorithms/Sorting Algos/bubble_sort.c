#include <stdio.h>

// Function Prototype --->
void bubble_sort(int arr[], int len);
void display(int arr[], int len);

int main()
{
    int max;
    printf("\nEnter elements of array :  \n");
    scanf("%d", &max);

    int arr[max];
    int i = 0;
    while (i < max)
    {
        printf("\nEnter element %d : ", i + 1);
        scanf("%d", &arr[i]);
        i++;
    }
    bubble_sort(arr, max);
    display(arr, max);
    return 0;
}

// Function Body --->
void display(int arr[], int len)
{
    int i = 0;
    while (i < len)
        printf(" %d ", arr[i++]);
}

void bubble_sort(int arr[], int len)
{
    for (int i = 0; i <= len; i++)
    {
        for (int j = 0; j <= (len - i - 1); j++)
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
