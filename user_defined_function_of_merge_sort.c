#include <stdio.h>
// Coding to merge the two sorted array without using a Merge_Sort Algorithm.
void getArray(int *Arr, int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        printf("%d\t", Arr[i]);
    }
}
void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void bubble_sort(int *Arr, int n)
{

    for (int i = 0; i < n - 1; i = i + 1)
    {

        for (int j = 0; j < n - 1 - i; j = j + 1)
        {
            if (Arr[j] > Arr[j + 1])
            {
                swap(&Arr[j], &Arr[j + 1]);
            }
        }
    }
}
void merge_arrays(int A[], int B[], int C[], int m, int n)
{
    for (int i = 0; i < m; i = i + 1)
    {
        C[i] = A[i];
    }
    for (int i = 0; i < n; i = i + 1)
    {
        C[i + 10] = B[i];
    }
}
int main(void)
{
    int arr1[] = {-5, 11, 2, 25, 3, 17, 123, 7, -18, 15}; //  Unorted Array1
    int m = 10;
    printf("\nThe array 1 before sorting is given as :\n");
    getArray(arr1, m);

    int arr2[] = {6, 1, 13, 4, -77, 9}; //  Unorted Array2
    int n = 6;
    printf("\nThe array 2 before sorting is given as :\n");
    getArray(arr2, n);


    int a = m + n;
    int arr3[a];
    merge_arrays(arr1,arr2,arr3,m,n);
    // for (int i = 0; i < m; i = i + 1)
    // {
    //     arr3[i] = arr1[i];
    // }
    // for (int i = 0; i < n; i = i + 1)
    // {
    //     arr3[i + 10] = arr2[i];
    // }

    printf("\nThe array 3 before sorting is given as :\n");
    getArray(arr3, a);

    bubble_sort(arr1, m);
    printf("\nThe array 1 after sorting is given as :\n");
    getArray(arr1, m);

    bubble_sort(arr2, n);
    printf("\nThe array 2 after sorting is given as :\n");
    getArray(arr2, n);

    bubble_sort(arr3, a);
    printf("\nThe array 3 after sorting is given as :\n");
    getArray(arr3, a);

    return 0;
}