#include <stdio.h>
// MergeSort a single array Sorting Algorithm.
void getArray(int *Arr, int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        printf("%d\t", Arr[i]);
    }
}
void Merge_Sort(int A[], int B[], int n, int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
}
void Copy_Arr(int A[], int B[], int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        A[i] = B[i];
    }
}
int main(void)
{
    int arr1[] = {-5, 1, 2, 5, 13, -6, 3, 17, 82, 95}; // Already Sorted Array1
    int n = 10;
    int arr2[n];
    Merge_Sort(arr1, arr2, 10, 0, 4, 9);
    Copy_Arr(arr1, arr2, n);
    getArray(arr1, n);

    return 0;
}