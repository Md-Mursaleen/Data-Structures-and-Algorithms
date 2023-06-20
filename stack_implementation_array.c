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
    // struct stack s;
    // s.size=80;
    // s.top=-1;
    // s.arr=(int *)malloc(s.size*sizeof(int));
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    (*s).size = 80;
    (*s).top = -1;
    (*s).arr = (int *)malloc((*s).size * sizeof(int));
    // //Pushing the satck manually.
    // (*s).arr[0]=7;
    // (*s).top++;
    if (isEmpty(s))
    {
        printf("The stack is Empty");
    }
    else
    {
        printf("The stack is not empty");
    }

    return 0;
}