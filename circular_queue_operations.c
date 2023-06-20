#include <stdio.h>
#include <stdlib.h>
// Circular Queue operations.
struct Circular_Queue
{
    int size;
    int f, r;
    int *arr;
};
int isEmpty(struct Circular_Queue *a)
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
int isFull(struct Circular_Queue *a)
{
    if (((*a).r + 1) % (*a).size == (*a).f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void traversal_CircularQueue(struct Circular_Queue *a)
{
    while ((*a).f != (*a).r)
    {
        printf("%d\t", (*a).arr[(*a).f]);
        (*a).f = ((*a).f + 1) % (*a).size;
    }
}

void enqueue(struct Circular_Queue *a, int val)
{
    if (isFull(a))
    {
        printf("Queue overflow,you cannot add more elements in the circular queue\n");
    }
    else
    {
        (*a).arr[(*a).r] = val;
        (*a).r = ((*a).r + 1) % (*a).size;
    }
}
int dequeue(struct Circular_Queue *a)
{

    int val = -1;
    if (isEmpty(a))
    {
        printf("Queue underflow,you cannot remove more elements from the circular queue\n");
    }
    else
    {
        val = (*a).arr[(*a).f];
        (*a).f = ((*a).f + 1) % (*a).size;
    }
    return val;
}
int main(void)
{
    struct Circular_Queue ptr;
    ptr.size = 9;
    ptr.f = ptr.r = 0;
    ptr.arr = (int *)malloc(ptr.size * sizeof(int));
    enqueue(&ptr, 12);
    enqueue(&ptr, 1);
    enqueue(&ptr, 8);

    if (isFull(&ptr))
    {
        printf("The Circular Queue is Full\n.");
    }
    else
    {
        printf("The Circular Queue is not Full\n.");
    }

    printf("The dequeueing element is %d\n", dequeue(&ptr));
    printf("The dequeueing element is %d\n", dequeue(&ptr));
    printf("The dequeueing element is %d\n", dequeue(&ptr));

    printf("The elements in the Circular Queue after all operations is given as :\n");
    traversal_CircularQueue(&ptr);

    if (isEmpty(&ptr))
    {
        printf("The Circular Queue is Empty\n.");
    }
    else
    {
        printf("The Circular Queue is not Empty\n.");
    }

    return 0;
}