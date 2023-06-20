#include <stdio.h>
#include <stdlib.h>
// Stack Peek() operation.
struct stack
{
    int size;
    int top;
    int *arr;
};
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
void stack_push(struct stack *a, int val)
{
    if (isFull(a))
    {
        printf("The stack overflow");
    }
    else
    {
        (*a).top++;
        (*a).arr[(*a).top] = val;
    }
}
int stack_peek(struct stack *a, int position)
{
    if ((*a).top - position + 1 < 0)
    {
        printf("Invalid Position : You Cannot access that element");
        return -1;
    }
    else
    {
        return (*a).arr[(*a).top - position + 1];
    }
}

int main(void)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    (*ptr).size = 9;
    (*ptr).top = -1;
    (*ptr).arr = (int *)malloc((*ptr).size * sizeof(int));
    stack_push(ptr, 12);
    stack_push(ptr, 1);
    stack_push(ptr, 56);
    stack_push(ptr, 5);
    stack_push(ptr, 9);
    stack_push(ptr, 10);
    stack_push(ptr, 40);
    stack_push(ptr, 67);
    stack_push(ptr, 2);
    for (int k = 1; k <=9; k = k + 1)
    {
        int val;
        val = stack_peek(ptr, k);
        printf("The value obtained at %dth position is :\%d\n", k, val);
    }

    return 0;
}