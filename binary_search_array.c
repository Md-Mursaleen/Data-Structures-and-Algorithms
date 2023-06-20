#include <stdio.h>
// Binary Search in C.
void set_myArr(int arr[], int n)
{
    printf("The array must be sorted for searching an element using binary search\n");
    for (int i = 0; i < n; i = i + 1)
    {
        printf("Enter the element at %d th position :\n", i);
        scanf("%d", &arr[i]);
    }
}
void binary_searchmyArr(int arr[], int s, int ele)
{
    int low, mid, high;
    low = 0;
    high = s - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == ele)
        {
            printf("The element %d is found at index %d", ele, mid);
        }
        if (arr[mid] < ele)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("The element %d is not found in the given sorted array", ele);
}

int main(void)
{
    int myArr[100];
    int total_size = 100;
    printf("The total size of the array is :%d\n", total_size);
    int used_size;
    printf("Enter the size that you want to be used now :");
    scanf("%d", &used_size);
    set_myArr(myArr, used_size);

    int ele;
    printf("Enter the element that you want to search (binary search) it in the given array :");
    scanf("%d", &ele);
    binary_searchmyArr(myArr, used_size, ele);

    return 0;
}