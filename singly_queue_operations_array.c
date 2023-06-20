#include <stdio.h>
#include <stdlib.h>
// Singly Queue Operations(Enqueue , Dequeue and Display) implementation by Arrays.
struct queue
{
    int size;
    int f, r;
    int *arr;
};
int isEmpty(struct queue *a)
{
    if ((*a).f == (*a).r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct queue *a)
{
    if ((*a).r == (*a).size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void traversal_SinglyQueue(struct queue *a)
{
    while ((*a).f != (*a).r)
    {
        printf("%d\t", (*a).arr[(*a).f]);
        (*a).f = (*a).f + 1;
    }
}

int enqueue(struct queue *a, int val)
{
    if (isFull(a))
    {
        printf("The Queue is full that means queue is overflow,you cannot add more element in it.\n");
        return 1;
    }
    else
    {
        (*a).r++;
        (*a).arr[(*a).r] = val;
    }
}
int dequeue(struct queue *a)
{
    if (isEmpty(a))
    {
        printf("The Queue is empty that means queue is underflow,you cannot remove more element from it.\n");
        return 1;
    }
    else
    {
        (*a).f++;
        int val = (*a).arr[(*a).f];
        return val;
    }
}
int main(void)
{
    struct queue ptr;
    ptr.size = 7;
    ptr.f = ptr.r = -1;
    ptr.arr = (int *)malloc(ptr.size * sizeof(int));

    enqueue(&ptr, 12);
    enqueue(&ptr, 2);
    enqueue(&ptr, 16);
    enqueue(&ptr, 67);
    enqueue(&ptr, 23);
    enqueue(&ptr, 6);


    if (isFull(&ptr))
    {
        printf("The Singly Queue is Full.\n");
    }
    else
    {
        printf("The Singly Queue is not Full.\n");
    }

    printf("The dequeueing element is %d\n", dequeue(&ptr));
    printf("The dequeueing element is %d\n", dequeue(&ptr));
    printf("The dequeueing element is %d\n", dequeue(&ptr));
    printf("The dequeueing element is %d\n", dequeue(&ptr));

    printf("The elements in the Circular Queue after all operations is given as :\n");
    traversal_CircularQueue(&ptr);

    if (isEmpty(&ptr))
    {
        printf("\nThe Singly Queue is Empty.");
    }
    else
    {
        printf("\nThe Singly Queue is not Empty.");
    }

    return 0;
}