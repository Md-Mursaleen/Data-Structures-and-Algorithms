#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *a)
{
    if ((*a).top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *a)
{
    if ((*a).top == (*a).size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(void)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    (*ptr).size = 9;
    (*ptr).top = -1;
    (*ptr).arr = (int *)malloc((*ptr).size * sizeof(int));
    if (isEmpty(ptr))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }
    if (isFull(ptr))
    {
        printf("The stack is overflow\n");
    }
    else
    {
        printf("The stack is not overflow\n");
    }

    return 0;
}