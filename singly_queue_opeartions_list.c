#include <stdio.h>
#include <stdlib.h>
struct node *f = NULL;
struct node *b = NULL;

struct node
{
    int data;
    struct node *ptr;
};
void traversallinked_list(struct node *a)
{
    printf("The elements in the linked list (Queue) is :\n");
    while (a != NULL)
    {
        printf("%d\n", (*a).data);
        a = (*a).ptr;
    }
}
int isFull(struct node *a)
{
    struct node *N = (struct node *)malloc(sizeof(struct node));
    if (N == NULL)
    {
        printf("The Queue is Full,you cannot add more elements on it\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct node *a)
{
    if (a == NULL)
    {
        printf("The Queue is Empty,you cannot remove more elements from it\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
int enqueue(int val)
{
    struct node *N = (struct node *)malloc(sizeof(struct node));
    if (N == NULL)
    {
        printf("The Queue is Full,you cannot add more elements on it\n");
        return 1;
    }
    else
    {

        (*N).data = val;
        (*N).ptr = NULL;
        if (f == NULL)
        {
            f = b = N;
        }
        else
        {
            (*b).ptr = N;
            b = N;
        }
    }
}
int dequeue()
{
    int val = -1;
    if (f == NULL)
    {
        printf("The Queue is Empty,you cannot remove more elements from it\n");
    }
    else
    {
        struct node *ptr = f;
        f = (*f).ptr;
        val = (*ptr).data;
        free(ptr);
    }
    return val;
}
int main(void)
{
    // Dequeueing the elements from the queue.
    printf("Dequeueing element is %d\n", dequeue());
    // Enqueueing the elements in the queue.
    enqueue(12);
    enqueue(1);
    enqueue(9);
    // Checking wheather it is empty or full.
    // isEmpty(f);
    traversallinked_list(f);
    printf("Dequeueing element is %d\n", dequeue());
    traversallinked_list(f);

    return 0;
}