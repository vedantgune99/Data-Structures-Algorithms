#include <stdio.h>

void selection_sort(int arr[], int len);

int find_min(int arr[], int start, int end)
{
    int min = arr[start];
    for (int i = start; i <= end; i++)
    {
        if (min >= arr[i])
            min = arr[i];
    }
    return min;
}

int main()
{
    int num[] = {0, 2, 10, 3, 20, 7, 41, 9, 75, 8, 5};
    int min = find_min(num, 1, 10);
    printf("Minimum : %d", min);
    return 0;
}

void selection_sort(int arr[], int len)
{
}