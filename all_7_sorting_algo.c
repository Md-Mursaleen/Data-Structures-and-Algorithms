#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void getArray(int *Arr, int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        printf("%d\t", Arr[i]);
    }
}
void insertion_sortArr(int *Arr, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i = i + 1)
    {
        key = Arr[i];
        j = i - 1;
        while (j <= 0 && Arr[j] > key)
        {
            Arr[j + 1] = Arr[j];
            j--;
        }
        Arr[j + 1] = key;
    }
}
void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void bubble_sortAdaptive(int *Arr, int n)
{
    int isSorted = 0;
    for (int i = 0; i < n - 1; i = i + 1)
    {
        printf("\nWorking on pass number : %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j = j + 1)
        {
            if (Arr[j] > Arr[j + 1])
            {
                swap(&Arr[j], &Arr[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
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
void selection_sortArr(int *Arr, int n)
{
    int indexofMin;
    for (int i = 0; i < n; i = i + 1)
    {
        indexofMin = i;
        for (int j = i + 1; j < n; j = j + 1)
        {
            if (Arr[j] < Arr[indexofMin])
            {
                indexofMin = j;
            }
        }
        swap(&Arr[i], &Arr[indexofMin]);
    }
}
int partition(int Arr[], int low, int high)
{
    int pivot = Arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (Arr[i] <= pivot)
        {
            i++;
        }
        while (Arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&Arr[i], &Arr[j]);
        }
    } while (i < j);
    swap(&Arr[low], &Arr[j]);
    return j;
}
void Quick_Sort(int Arr[], int low, int high)
{
    int indexof_pivot;
    if (low < high)
    {
        indexof_pivot = partition(Arr, low, high); // returns the index of the pivot after partitioning.
        Quick_Sort(Arr, low, indexof_pivot - 1);
        Quick_Sort(Arr, indexof_pivot + 1, high);
    }
}
void Merge_Sort(int A[], int low, int mid, int high)
{
    int i, j, k;
    // n = high - low + 1;
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
void Count_Sort(int *A, int n)
{
    int i, j;
    int max = maximum(A, n); // returns the maximum element in the array.
    int *count_arr = (int *)malloc((max + 1) * sizeof(int));
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
    int arr[] = {5, 19, 2, 55, -3, -17};
    // int arr[] = {1,2,3,4,5,6};
    int n = 6;
    printf("The array before sorting is given as :\n");
    getArray(arr, n);

    // Adaptive sorting algorithm.
    bubble_sortAdaptive(arr, n);

    printf("\nThe array after sorting through adaptive bubble sort algo is given as :\n");
    getArray(arr, n);

    // Non-Adaptive sorting algorithm.
    bubble_sort(arr, n);

    printf("\nThe array after sorting through non-adaptive bubble sort algo is given as :\n");
    getArray(arr, n);

    // Insertion Sorting Algorithm.
    insertion_sortArr(arr, n);

    printf("\nThe array after sorting through insertion sort is given as :\n");
    getArray(arr, n);

    // selection Sorting Algorithm.
    selection_sortArr(arr, n);

    printf("\nThe array after sorting through selection sort is given as :\n");
    getArray(arr, n);

    // quicksort Sorting Algorithm.
    Quick_Sort(arr, 0, n - 1);

    printf("\nThe array after sorting through quicksort is given as :\n");
    getArray(arr, n);

    // mergesort Sorting Algorithm.
    recursive_MergeSort(arr, 0, n - 1);

    printf("\nThe array after sorting through mergesort is given as :\n");
    getArray(arr, n);

    printf("\nThe count sort algo is not work for the negative numbers in the array\n");
    int Arr[] = {15, 21, 2, 13, 3, 17, 82, 95}; // Already UnSorted Array
    int m = 8;
    // Count Sorting Algorithm.
    Count_Sort(Arr, n);

    printf("\nThe array after sorting through countsort is given as :\n");
    getArray(Arr, m);

    return 0;
}