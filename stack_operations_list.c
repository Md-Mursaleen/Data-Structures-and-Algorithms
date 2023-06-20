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
int stack_peek(struct node *a, int position)
{
    struct node *ptr = a;

    for (int i = 0; i < position - 1 && ptr != NULL; i = i + 1)
    {
        ptr = (*ptr).p;
    }
    if (ptr != NULL)
    {
        return (*ptr).data;
    }
    else
    {
        return -1;
    }
}
int stack_top(struct node *a)
{
    return (*a).data;
}
int stack_bottom(struct node *a)
{
    struct node *ptr = a;
    while (ptr != NULL)
    {
        ptr = (*ptr).p;
    }
    return (*ptr).data;
}

int main(void)
{
    struct node *top = NULL;
    top = stack_push(top, 12);
    top = stack_push(top, 78);
    top = stack_push(top, 1);
    traversallinked_list(top);

    int val;
    int i;
    printf("Enter the position at which you want to access the element in the stack :\n");
    scanf("%d", &i);
    val = stack_peek(top, i);
    printf("The value present at the %dth position is : %d\n", i, val);
    printf("The top most element present in the stack is %d\n", stack_top(top));
    printf("The bottom most element present in the stack is %d", stack_bottom(top));

    return 0;
}