#include <stdio.h>
// Traversal method in an array.
void display_myArr(int arr[], int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        printf("%d\t", arr[i]);
    }
}

void set_myArr(int arr[], int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        printf("Enter the element at %d th position :\n", i);
        scanf("%d", &arr[i]);
    }
}
void deletion_myArr(int arr[], int s, int ind)
{
    for (int i = ind; i < s - 1; i = i + 1)
    {
        arr[i] = arr[i + 1];
    }
}
int main(void)
{
    int myArr[100];
    int total_size = 100; // total size of the array.
    int used_size;        // used size of the array out of the total size.
    printf("The total size of the array is :%d\n", total_size);
    printf("Enter the size that you want to be used now :");
    scanf("%d", &used_size);
    set_myArr(myArr, used_size);

    int ind;
    printf("Enter the index at which you want to delete the element :");
    scanf("%d", &ind);

    deletion_myArr(myArr, used_size, ind); // deletion function is called to delete an element at any index in an array.
    used_size -= 1;

    // Printing the final array after deletion method.
    printf("The array after deleting an element is given as :\n");
    display_myArr(myArr, used_size);

    return 0;
}