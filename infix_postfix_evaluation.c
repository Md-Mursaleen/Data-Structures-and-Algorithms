#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
// Program to Evaluate the Postfix Expression.
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
int eval_postfix_exp(char *postfix_exp)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    (*ptr).size = 100;
    (*ptr).top = -1;
    (*ptr).arr = (char *)malloc((*ptr).size * sizeof(char));
    int val;
    char ch;
    for (int i = 0; postfix_exp[i] != ')'; i = i + 1)
    {
        ch = postfix_exp[i];
        if (isdigit(ch))
        {
            stack_push(ptr, ch - '0');
        }
        else if (ch == '/' || ch == '*' || ch == '-' || ch == '+')
        {
            int A = stack_pop(ptr);
            int B = stack_pop(ptr);
            switch (ch)
            {
            case '/':
                val = A / B;
                break;
            case '*':
                val = A * B;
                break;
            case '-':
                val = A - B;
                break;
            case '+':
                val = A + B;
                break;
            }
            stack_push(ptr, val);
        }
    }
    return stack_pop(ptr);
}
int main(void)
{
    printf("Put the closing parenthesis at the end of the postfix expression for terminate it\n");
    char *postfix_exp = "13456*+*/)";
    printf("The value of the postfix expression is given as : %d", eval_postfix_exp(postfix_exp));

    return 0;
}