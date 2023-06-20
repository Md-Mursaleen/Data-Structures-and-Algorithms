#include <stdio.h>
// QuickSort Sorting Algorithm.
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
// int partition(int Arr[], int low, int high)
// {
//     int pivot = Arr[low];
//     int i = low + 1;
//     int j = high;
//     do
//     {
//         while (Arr[i] <= pivot)
//         {
//             i++;
//         }
//         while (Arr[j] > pivot)
//         {
//             j--;
//         }
//         if (i < j)
//         {
//             swap(&Arr[i], &Arr[j]);
//         }
//     } while (i < j);
//     swap(&Arr[low], &Arr[j]);
//     return j;
// }
int main(void)
{
    int arr[] = {5, 19, 2, 55, -3, -17, 3, 7, 2, 5};
    // int arr[] = {1,2,3,4,5,6};
    int n = 10;
    printf("The array before sorting is given as :\n");
    getArray(arr, n);
    Quick_Sort(arr, 0, n - 1);
    printf("\nThe array after sorting through quicksort is given as :\n");
    getArray(arr, n);

    return 0;
}