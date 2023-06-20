#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
// Count Sorting Algorithm.
void getArray(int *Arr, int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        printf("%d\t", Arr[i]);
    }
}
// Function to find the maximum element in the array.
int maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i = i + 1)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}
void Count_Sort(int * A, int n)
{
    int i, j;
    int max = maximum(A, n); // returns the maximum element in the array.
    int* count_arr = (int *)malloc((max + 1) * sizeof(int));
    // Initialisation of the count array(auxiliary array) with zero value.
    for (i = 0; i < max + 1; i = i + 1)
    {
        count_arr[i] = 0;
    }
    // Increment the count array with 1 for each value of the array element.
    for (i = 0; i < n; i = i + 1)
    {
        // int j=A[i];
        count_arr[A[i]] = count_arr[A[i]] + 1;
    }

    i = 0;
    j = 0;
    while (i < (max + 1))
    {
        if (count_arr[i] > 0)
        {
            A[j] = i;
            count_arr[i] = count_arr[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int main(void)
{
    int arr[] = {15, 21, 2, 13, 3, 17, 82, 95}; // Already UnSorted Array
    int n = 8;
    Count_Sort(arr, n);
    getArray(arr, n);

    return 0;
}