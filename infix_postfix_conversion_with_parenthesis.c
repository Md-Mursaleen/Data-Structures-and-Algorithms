#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Program to convert the infix expression (with parenthesis) into postfix expression.
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
char stack_stacktop(struct stack *a)
{
    return (*a).arr[(*a).top];
}
int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_operator(char ch)
{
    if (ch == '(' || ch == ')' || ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char *infixto_postfix(char *infix_exp)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    (*ptr).size = 100;
    (*ptr).top = -1;
    (*ptr).arr = (char *)malloc((*ptr).size * sizeof(char));
    char *postfix_exp = (char *)malloc(strlen((infix_exp) + 1) * sizeof(char));
    int i = 0; // for infix_exp
    int j = 0; // for postfix_exp

    while (infix_exp[i] != '\0')
    {
        if (!is_operator(infix_exp[i]))
        {
            postfix_exp[j] = infix_exp[i];
            i++;
            j++;
        }
        else if (infix_exp[i] == '(')
        {
            stack_push(ptr, infix_exp[i]);
            i++;
        }
        else if (infix_exp[i] == ')')
        {
            while ((*ptr).arr[(*ptr).top] != '(')
            {
                postfix_exp[j] = stack_pop(ptr);
                j++;
            }
            stack_pop(ptr);
            i++;
        }
        else
        {
            if (precedence(infix_exp[i]) > precedence(stack_stacktop(ptr)))
            {
                stack_push(ptr, infix_exp[i]);
                i++;
            }
            else
            {
                postfix_exp[j] = stack_pop(ptr);
                j++;
            }
        }
    }
    while (!isEmpty(ptr))
    {
        postfix_exp[j] = stack_pop(ptr);
        j++;
    }
    postfix_exp[j] = '\0';
    return postfix_exp;
}
int main(void)
{
    char *infix_exp = "a+(b*c-(d/e^f)*g)*h";
    printf("The postfix expression is given as : %s", infixto_postfix(infix_exp));

    return 0;
}