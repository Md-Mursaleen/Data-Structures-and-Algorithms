#include <stdio.h>
// Traversal method in an array.
void display_myArr(int arr[], int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        printf("%d\t", arr[i]);
    }
}
// get the user input for the array.
void set_myArr(int arr[], int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        printf("Enter the element at %d th position :\n", i);
        scanf("%d", &arr[i]);
    }
}
// insertion method to insert an element at any position(start,end,at any specific index) in the array.
int insertion_myArr(int arr[], int w, int z, int y, int x)
{
    if (z >= w)
    {
        return -1;
    }
    else
    {
        for (int i = z - 1; i >= x; i = i - 1)
        {
            arr[i + 1] = arr[i];
        }
    }
    arr[x] = y;
    return 0;
}

int main(void)
{
    int myArr[100];
    int total_size = 100; // total size of the array.
    int used_size;        // used size of the array out of the total size.
    printf("The total size of the array is :%d\n", total_size);
    printf("Enter the size that you want to used now :");
    scanf("%d", &used_size);
    set_myArr(myArr, used_size);

    int ele;
    printf("Enter the element that you want to insert :");
    scanf("%d", &ele);

    int ind;
    printf("Enter the index at which you want to insert this element :\n");
    scanf("%d", &ind);

    insertion_myArr(myArr, total_size, used_size, ele, ind);   //insertion function is called to insert an element at any index in an array.
    used_size += 1;
    //Printing the final array after insertion method.
    printf("The array after inserting an element is given as :\n");
    display_myArr(myArr, used_size);

    return 0;
}