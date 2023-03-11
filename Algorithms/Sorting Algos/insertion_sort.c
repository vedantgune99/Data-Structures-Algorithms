#include <stdio.h>

// Function Prototype --->
void insertion_sort(int arr[], int len);
void display(int arr[], int len);

int main()
{
    int len;
    printf("\nEnter number of elements : ");
    scanf("%d", &len);

    int num[len];
    for (int i = 0; i < len; i++)
    {
        printf("\nEnter element %d : ", i + 1);
        scanf("%d", &num[i]);
    }

    printf("\n Before Sorting --->");
    display(num, len);

    insertion_sort(num, 6);
    printf("\n After Sorting --->");
    display(num, len);

    return 0;
}

// Function Body --->
void insertion_sort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int current = arr[i];
        int j = i - 1;

        // All elements will shift towards right...
        while (j >= 0 && arr[j] >= current)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Now putting current to correct position...
        arr[j + 1] = current;
    }
}

void display(int arr[], int len)
{
    int i = 0;
    while (i < len)
        printf(" %d ", arr[i++]);
}