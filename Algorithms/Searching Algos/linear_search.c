#include <stdio.h>
#define MAX 5

// Function Prototype --->
int linearSearch(int arr[], int data);

int main()
{
    int arr[MAX];
    int i = 0, x;
    while (i++ < MAX)
    {
        printf("\n>>>Enter element %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n>>>Enter data you want to find : ");
    scanf("%d", &x);

    int index = linearSearch(arr, x);

    if (index >= 0)
        printf("\nElement found at %d!", index);
    else
        printf("\nElement not found!");

    return 0;
}

// Linear Search on Array --->
int linearSearch(int arr[], int data)
{
    int index = 0;
    while (index++ < MAX)
    {
        if (arr[index] == data)
            return index;
    }
    return (-1);
}