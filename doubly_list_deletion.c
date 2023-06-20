#include <stdio.h>
#include <stdlib.h>
// ADT for the Doubly Linked List.
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
// Traversal method to access all the elements of the Doubly Linked List.
void traversallinked_list(struct node *a)
{
    printf("The elements in the linked list is :\n");
    while (a != NULL)
    {
        printf("%d\n", (*a).data);
        a = (*a).next;
    }
}
struct node *deletionat_start(struct node *a)
{
    struct node *p = a;
    struct node *q = (*a).next;
    (*q).prev = NULL;
    free(p);
    return q;
}
struct node *deletionat_index(struct node *a, int index)
{
    struct node *p = a;
    struct node *q = (*a).next;
    int i = 0;
    while (i != index - 1)
    {
        p = (*p).next;
        q = (*q).next;
        i = i + 1;
    }
    if ((*q).next != NULL)
    {
        (*p).next = (*q).next;
    }
    else
    {
        (*p).next = NULL;
    }
    free(q);
    return a;
}
struct node *deletionat_end(struct node *a)
{
    struct node *p = a;
    struct node *q = (*a).next;
    while ((*q).next != NULL)
    {
        p = (*p).next;
        q = (*q).next;
    }
    (*p).next = NULL;
    free(q);
    return a;
}
int main(void)
{
    // Creating the head node with all the other nodes.
    struct node *head_node;
    struct node *second_node;
    struct node *third_node;
    struct node *fourth_node;
    struct node *fifth_node;

    // Allocate memory to node in heap memory for linked list.
    head_node = (struct node *)malloc(sizeof(struct node));
    second_node = (struct node *)malloc(sizeof(struct node));
    third_node = (struct node *)malloc(sizeof(struct node));
    fourth_node = (struct node *)malloc(sizeof(struct node));
    fifth_node = (struct node *)malloc(sizeof(struct node));

    // linking the head node with first node.
    (*head_node).data = 7;
    (*head_node).prev = NULL;
    (*head_node).next = second_node;

    // linking the second node with third node.
    (*second_node).data = 11;
    (*second_node).prev = head_node;
    (*second_node).next = third_node;

    // linking the third node with NULL.
    (*third_node).data = 16;
    (*third_node).prev = second_node;
    (*third_node).next = fourth_node;

    // linking the third node with NULL.
    (*fourth_node).data = 4;
    (*fourth_node).prev = third_node;
    (*fourth_node).next = fifth_node;

    // linking the fifth node with NULL.
    (*fifth_node).data = 11;
    (*fifth_node).prev = fourth_node;
    (*fifth_node).next = NULL;
    traversallinked_list(head_node);

    // Deletion at the begining.
    head_node = deletionat_start(head_node);
    printf("The linked list after deletion is looked like :\n");
    traversallinked_list(head_node);

    // Deletion at the particular position.
    int ind;
    printf("Enter the index at which you want to insert an element :\n");
    scanf("%d", &ind);
    head_node = deletionat_index(head_node, ind);
    printf("The linked list after deletion is looked like :\n");
    traversallinked_list(head_node);

    // Deletion at the end.
    head_node = deletionat_end(head_node);
    printf("The linked list after deletion is looked like :\n");
    traversallinked_list(head_node);

    return 0;
}