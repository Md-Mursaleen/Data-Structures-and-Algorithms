#include <stdio.h>
// Bubble Sort Program in C.
void printArray(int *Arr, int n)
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

int main(void)
{
    int arr[] = {5, 19, 2, 55, -3, -17};
    // int arr[] = {1,2,3,4,5,6};
    int n = 6;
    printf("The array before sorting is given as :\n");
    printArray(arr, n);
    
    //Adaptive sorting algorithm.

    bubble_sortAdaptive(arr, n);
    printf("\nThe array after sorting through adaptive bubble sort algo is given as :\n");
    printArray(arr, n);

    //Non-Adaptive sorting algorithm.
    bubble_sort(arr, n);
    printf("\nThe array after sorting through non-adaptive bubble sort algo is given as :\n");
    printArray(arr, n);


    return 0;
}