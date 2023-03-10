#include <stdio.h>

// Function Prototype --->
void selection_sort(int arr[], int len);
int find_min_index(int arr[], int start, int end);
void display(int arr[], int len);

int main()
{
    // Input of maxsize
    int max;
    printf("\n>>>Enter number of elements : ");
    scanf("%d", &max);

    // Taking input of array
    int num[max];
    int i = 0;
    while (i < max)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &num[i++]);
    }

    printf("\nBefore Sorting ---> \n");
    display(num, max);

    selection_sort(num, max);
    printf("\nAfter Sorting ---> \n");
    display(num, max);

    return 0;
}

// Function finds & returns the index of minimum element --->
int find_min_index(int arr[], int start, int end)
{
    int min = arr[start];
    for (int i = start; i < end; i++)
    {
        if (min >= arr[i])
            min = arr[i];
    }
    for (int j = start; j < end; j++)
    {
        if (min == arr[j])
            return j;
    }
}

// Sorts the dataset using selection sort algo --->
void selection_sort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int min = find_min_index(arr, i, len);
        if (arr[i] >= arr[min])
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// display the dataset --->
void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf(" %d ", arr[i]);
}