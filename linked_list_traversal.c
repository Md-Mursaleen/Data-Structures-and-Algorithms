#include <stdio.h>
#include <stdlib.h>

struct node
{
    int element;
    struct node *ptr;
};
void traversallinked_list(struct node *a)
{
    printf("The elements in the linked list is :\n");
    while (a != NULL)
    {
        printf("%d\n", (*a).element);
        a = (*a).ptr;
    }
}
int main(void)
{
    struct node *head_node;
    struct node *second_node;
    struct node *third_node;
    // Allocate memory for node in heap memory in linked list.
    head_node = (struct node *)malloc(sizeof(struct node));
    second_node = (struct node *)malloc(sizeof(struct node));
    third_node = (struct node *)malloc(sizeof(struct node));
    // linking the head node with first node.
    (*head_node).element = 7;
    (*head_node).ptr = second_node;
    // linking the second node with third node.
    (*second_node).element = 11;
    (*second_node).ptr = third_node;
    // linking the thied node with NULL.
    (*third_node).element = 16;
    (*third_node).ptr = NULL;
    traversallinked_list(head_node);

    return 0;
}