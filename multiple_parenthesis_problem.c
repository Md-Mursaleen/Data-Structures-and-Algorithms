#include <stdio.h>
#include <stdlib.h>
// Multiple Paranthesis Matching Problem using stack.

struct stack
{
    int size;
    int top;
    char *arr;
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
void stack_push(struct stack *a, char val)
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
char stack_pop(struct stack *a)
{
    if (isEmpty(a))
    {
        printf("The stack underflow");
        return -1;
    }
    else
    {
        char val = (*a).arr[(*a).top];
        (*a).top--;
        return val;
    }
}
// char stack_top(struct stack *a)
// {
//     return (*a).arr[(*a).top];
// }
int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int multipleparenthesis_matching(char *a)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    (*ptr).size = 100;
    (*ptr).top = -1;
    (*ptr).arr = (char *)malloc((*ptr).size * sizeof(char));
    for (int i = 0; a[i] != '\0'; i = i + 1)
    {
        if (a[i] == '(' || a[i] == '[' || a[i] == '{')
        {
            {
                stack_push(ptr, a[i]);
            }
        }
        else if (a[i] == ')' || a[i] == ']' || a[i] == '}')
        {
            if (isEmpty(ptr))
            {
                return 0;
            }
            else
            {
                char popped_ch = stack_pop(ptr);
                if (!match(popped_ch,a[i]))
                {
                    return 0;
                }
            }
        }
    }
    if (isEmpty(ptr))
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
    char *exp = "(3-2)*7-[34*2}*6-{23+1]";
    if (multipleparenthesis_matching(exp))
    {
        printf("\nThe parenthesis is matching");
    }
    else
    {
        printf("\nThe parenthesis is not matching");
    }

    return 0;
}