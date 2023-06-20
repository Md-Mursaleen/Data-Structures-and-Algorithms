#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// Traversal method in the Linked List.
void traversal_linkedlist(struct node *a)
{
    while ((*a).next != NULL)
    {
        printf("%d\n", (*a).data);
        a = (*a).next;
    }
    printf("%d\n", (*a).data);
}
struct node *deleteat_start(struct node *a)
{
    struct node *p = a;
    a = (*p).next;
    free(p);
    return a;
}
struct node *deleteat_end(struct node *a)
{
    struct node *p = a;
    struct node *q = (*p).next;
    while ((*q).next != NULL)
    {
        q = (*q).next;
        p = (*p).next;
    }

    (*p).next = NULL;
    free(q);
    return a;
}
struct node *deletein_between(struct node *a, int index)
{
    struct node *p = a;
    struct node *q = (*p).next;
    int i = 0;
    while (i != index - 1)
    {
        p = (*p).next;
        q = (*q).next;
        i++;
    }

    (*p).next = (*q).next;
    free(q);
    return a;
}
struct node *deletewith_value(struct node *a, int value)
{
    struct node *p = a;
    struct node *q = (*p).next;
    while ((*q).data != value && (*q).next != NULL)
    {
        p = (*p).next;
        q = (*q).next;
    }
    if ((*q).data == value)
    {
        (*p).next = (*q).next;
        free(q);
    }

    return a;
}
int main(void)
{
    // Creating the head node with all the other nodes.
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;
    struct node *sixth;

    // Allocating the heap memory to each node.
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));

    // Linking the head node with the second node.
    (*head).data = 2;
    (*head).next = second;

    // Linking the second node with the third node.
    (*second).data = 67;
    (*second).next = third;

    // Linking the third node with the fourth node.
    (*third).data = 21;
    (*third).next = fourth;

    // Linking the fourth node with the fifth node.
    (*fourth).data = 30;
    (*fourth).next = fifth;

    // Linking the fifth node with the NULL node.
    (*fifth).data = 40;
    (*fifth).next = sixth;

    // Linking the sixth node with the NULL node.
    (*sixth).data = 12;
    (*sixth).next = NULL;
    traversal_linkedlist(head);

    // Deleting the node at the beginning from the linked list.
    head = deleteat_start(head);
    printf("The linked list after deletion is looked like :\n");
    traversal_linkedlist(head);

    // Deleting the node in between the two nodes from the linked list.
    int ind;
    printf("Enter the index at which you want to delete the node in the linked list :\n");
    scanf("%d", &ind);
    head = deletein_between(head, ind);
    printf("The linked list after deletion is looked like :\n");
    traversal_linkedlist(head);

    // Deleting the node at the end from the linked list.
    head = deleteat_end(head);
    printf("The linked list after deletion is looked like :\n");
    traversal_linkedlist(head);

    // Deleting the node with a specific value from the linked list.
    int val;
    printf("Enter the value at which you want to delete a particular node :\n");
    scanf("%d", &val);
    head = deletewith_value(head, val);
    printf("The linked list after deletion is looked like :\n");
    traversal_linkedlist(head);

    return 0;
}