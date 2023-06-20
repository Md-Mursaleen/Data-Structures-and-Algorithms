#include <stdio.h>
#include <stdlib.h>
// Stack stacktop() and stackbottom() operations.
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
int stack_stacktop(struct stack *a)
{
    return (*a).arr[(*a).top];
}
int stack_stackbottom(struct stack *a)
{
    return (*a).arr[0];
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
    printf("The bottom most element present in the stack is %d\n", stack_stackbottom(ptr));
    printf("The top most element present in the stack is %d\n", stack_stacktop(ptr));

    return 0;
}