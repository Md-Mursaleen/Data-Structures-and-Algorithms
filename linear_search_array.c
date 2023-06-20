#include <stdio.h>
// Linear Search in C.
void set_myArr(int arr[], int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        printf("Enter the element at %d th position :\n", i);
        scanf("%d", &arr[i]);
    }
}
void linear_searchmyArr(int arr[], int s, int ele)
{
    for (int i = 0; i < s; i = i + 1)
    {
        if (arr[i] == ele)
        {
            printf("The element %d is found at index %d", ele, i);
        }
    }
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
    printf("Enter the element that you want to search it in the given array :");
    scanf("%d", &ele);
    linear_searchmyArr(myArr, used_size, ele);

    return 0;
}