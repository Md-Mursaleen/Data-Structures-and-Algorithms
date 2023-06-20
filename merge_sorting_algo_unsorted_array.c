#include <stdio.h>
#include <stdio.h>
// MergeSort a single array (Unsorted) Sorting Algorithm.
void getArray(int *Arr, int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        printf("%d\t", Arr[i]);
    }
}
// void Copy_Arr(int A[], int B[], int n)
// {
//     for (int i = 0; i < n; i = i + 1)
//     {
//         A[i] = B[i];
//     }
// }
void Merge_Sort(int A[], int low, int mid, int high)
{
    int i, j, k;
    //n = high - low + 1;
    int B[100];
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
    for (int i = low; i <= high; i = i + 1)
    {
        A[i] = B[i];
    }
}
void recursive_MergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        recursive_MergeSort(A, low, mid);
        recursive_MergeSort(A, mid + 1, high);
        Merge_Sort(A, low, mid, high);
    }
}

int main(void)
{
    int arr[] = {15, 21, 2, -5, 13, -6, 3, 17, 82, 95}; // Already UnSorted Array
    int n = 10;
    recursive_MergeSort(arr, 0, n - 1);
    getArray(arr, n);

    return 0;
}