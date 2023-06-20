#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *p;
};
void traversallinked_list(struct node *a)
{
    printf("The elements in the linked list is :\n");
    while (a != NULL)
    {
        printf("%d\n", (*a).data);
        a = (*a).p;
    }
}
int isEmpty(struct node *a)
{
    if (a == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct node *a)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node *stack_push(struct node *a, int val)
{
    if (isFull(a))
    {
        printf("Stack overflow : you cannot push another element now.");
    }
    else
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        (*ptr).data = val;
        (*ptr).p = a;
        a = ptr;
        return a;
    }
}
int stack_pop(struct node **a)
{
    if (isEmpty(*a))
    {
        printf("Stack underflow : you cannot pop elements now.");
    }
    else
    {
        struct node *ptr = *a;
        int val;
        val = (*ptr).data;
        *a = (**a).p;
        free(ptr);
        return val;
    }
}

int main(void)
{
    struct node *top = NULL;
    top = stack_push(top, 12);
    top = stack_push(top, 78);
    top = stack_push(top, 1);
    traversallinked_list(top);
    int value;
    value = stack_pop(&top);
    printf("The value poped out is : %d\n", value);
    traversallinked_list(top);

    return 0;
}