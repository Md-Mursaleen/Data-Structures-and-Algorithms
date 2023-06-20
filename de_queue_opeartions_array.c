#include <stdio.h>
#include <stdlib.h>
struct DEQueue
{
    int size;
    int f, b;
    int *arr;
};
int isEmpty(struct DEQueue *a)
{
    if ((*a).f == (*a).b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct DEQueue *a)
{
    if ((*a).b == (*a).size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int enqueue_b(struct DEQueue *a, int val)
{
    if (isFull(a))
    {
        printf("The Queue is Full,you cannot add more elements in it\n");
        return 1;
    }
    else
    {
        (*a).b = (*a).b + 1;
        (*a).arr[(*a).b] = val;
    }
}
int enqueue_f(struct DEQueue *a, int val)
{
    if (isFull(a))
    {
        printf("The Queue is Full,you cannot add more elements in it\n");
        return 1;
    }
    else
    {
        (*a).arr[(*a).f] = val;
        (*a).f--;
    }
}
int dequeue_f(struct DEQueue *a)
{
    int val;
    if (isEmpty(a))
    {
        printf("The Queue is Empty,you cannot remove more elements from it\n");
    }
    else
    {
        (*a).f = (*a).f + 1;
        int val = (*a).arr[(*a).f];
    }
    return val;
}
int dequeue_b(struct DEQueue *a)
{
    int val = -1;
    if (isEmpty(a))
    {
        printf("The Queue is Empty,you cannot remove more elements from it\n");
    }
    else
    {
        int val = (*a).arr[(*a).b];
        (*a).b--;
    }
    return val;
}
int main(void)
{
    struct DEQueue ptr;
    ptr.size = 100;
    //ptr.f = ptr.size - 1;
     ptr.f=ptr.b = -1;
    ptr.arr = (int *)malloc(ptr.size * sizeof(int));
    enqueue_b(&ptr, 2);
    enqueue_b(&ptr, 32);
    // if (isFull(&ptr))
    // {
    //     printf("The Queue is Full.");
    // }
    printf("The dequeueing element is %d\n", dequeue_f(&ptr));
    printf("The dequeueing element is %d\n", dequeue_f(&ptr));

    return 0;
}