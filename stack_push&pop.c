#include <stdio.h>
#include <stdlib.h>
// Stack Push(),pop() operations.
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
int stack_pop(struct stack *a)
{
    if (isEmpty(a))
    {
        printf("The stack underflow");
        return -1;
    }
    else
    {
        int val = (*a).arr[(*a).top];
        (*a).top--;
        return val;
    }
}
int main(void)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    (*ptr).size = 9;
    (*ptr).top = -1;
    (*ptr).arr = (int *)malloc((*ptr).size * sizeof(int));
    printf("%d\n", isEmpty(ptr));
    printf("%d\n", isFull(ptr));
    int i;
    printf("Enter the element that you want to push in the stack :\n");
    scanf("%d", &i);
    stack_push(ptr, i);
    printf("%d\n", isEmpty(ptr));
    printf("%d\n", isFull(ptr));
    stack_pop(ptr);
     printf("%d\n",isEmpty(ptr));
    printf("%d\n",isFull(ptr));

    return 0;
}