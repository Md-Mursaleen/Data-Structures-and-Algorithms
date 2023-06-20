#include <stdio.h>
// Insertion Sort Program in C.
void printArr(int *Arr, int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        printf("%d\t", Arr[i]);
    }
}
void insertion_sortArr(int *Arr, int n)
{
    int j, key;
    for (int i = 1; i <= n - 1; i = i + 1)
    { // Loop for number of passes.
        key = Arr[i];
        j = i - 1;
        while (j >= 0 && Arr[j] > key)
        {
            Arr[j + 1] = Arr[j];
            j--;
        }
        Arr[j+1] = key;
    }
}
int main(void)
{
    //           0  1   2   3   4    5
    int arr[] = {5, 19, 2, 55, -3, -17};
    int n = 6;

    printf("The array before sorting is given as :\n");
    printArr(arr, n);
    // Insertion Sorting Algorithm.
    insertion_sortArr(arr, n);

    printf("The array after sorting is given as :\n");
    printArr(arr, n);

    return 0;
}