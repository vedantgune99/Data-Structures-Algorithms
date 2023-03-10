#include <stdio.h>
#define MAX 5

void selection_sort(int arr[], int len);
int find_min_index(int arr[], int start, int end);

int main()
{
    int num[MAX] = {5, 4, 3, 2, 1};
    // int min = find_min(num, 1, 10);

    printf("\nBefore Sorting....");
    for (int i = 0; i < MAX; i++)
        printf("%d, ", num[i]);

    selection_sort(num, MAX);
    printf("\nAfter Sorting....");
    for (int i = 0; i < MAX; i++)
        printf("%d, ", num[i]);

    return 0;
}

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