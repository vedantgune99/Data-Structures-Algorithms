#include <stdio.h>
#define MAX 5

// Function Prototype --->
int binSearch(int arr[], int data);

int main()
{
    int arr[MAX];
    int i = 0;
    // Taking input of array...
    while (i++ < MAX)
    {
        printf("\n>>>Enter element %d : ", i);
        scanf("%d", &arr[i]);
    }

    // Data to be found...
    int x;
    printf("\n>>>Enter data you want to find : ");
    scanf("%d", &x);

    // Final result evaluation...
    int index = binSearch(arr, x);
    if (index >= 0)
        printf("\nElement found at %d!", index);
    else
        printf("\nElement not found!");

    return 0;
}

// Binary Search on Array --->
int binSearch(int arr[], int data)
{
    int first = 0;
    int last = MAX - 1;
    int mid = (first + last) / 2;
    while (first < last)
    {
        mid = (first + last) / 2;
        if (arr[mid] == data)
            return mid;

        else if (arr[mid] < data)
            first = mid + 1;

        else
            last = mid - 1;
    }
    return (-1);
}