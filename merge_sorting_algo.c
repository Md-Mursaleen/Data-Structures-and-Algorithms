#include <stdio.h>
// MergeSort Sorting Algorithm.
void getArray(int *Arr, int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        printf("%d\t", Arr[i]);
    }
}
void Merge_Sort(int A[], int B[], int C[], int m, int n)
{
    int i, j, k;
    i, j, k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k] = A[i];
            i++;
            k++;
        }
        else
        {
            C[k] = B[j];
            j++;
            k++;
        }
    }
    while (i < m)
    {
        C[k] = A[i];
        i++;
        k++;
    }
    while (j < n)
    {
        C[k] = B[j];
        j++;
        k++;
    }
}
int main(void)
{
    int arr1[] = {-5, 1, 2, 5, 13, 17, 23, 77}; // Already Sorted Array1
    int m = 8;
    int arr2[] = {6, 11, 32, 41, 77, 90}; // Already Sorted Array2
    int n = 6;
    int a = m + n;
    int arr3[a];
    // printf("The array before sorting is given as :\n");
    // getArray(arr, n);
    Merge_Sort(arr1, arr2, arr3, m, n);
    getArray(arr3, a);

    return 0;
}