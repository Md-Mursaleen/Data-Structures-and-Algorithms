#include <stdio.h>
#include <stdlib.h>
// All the operations in the Circular Linked List.
struct node
{
    int data;
    struct node *next;
};
// Traversal method in the Circular Linked List.
void traversal_linkedlist(struct node *a)
{
    printf("The elements in the linked list is :\n");
    struct node *p = a;
    do
    {
        printf("%d\n", (*p).data);
        p = (*p).next;
    } while ((*p).next != a);
    printf("%d\n", (*p).data);
}
struct node *deletionat_start(struct node *a)
{
    struct node *p = (*a).next;
    struct node *q = (*p).next;
    while ((*q).next != a)
    {
        q = (*q).next;
    }
    (*q).next = p;
    free(a);
    return p;
}
struct node *deletionat_end(struct node *a)
{
    struct node *p = a;
    struct node *q = (*a).next;
    while ((*q).next != a)
    {
        p = (*p).next;
        q = (*q).next;
    }
    (*p).next = a;
    free(q);
    return a;
}
struct node *deletionat_index(struct node *a, int index)
{
    struct node *p = a;
    struct node *q = (*a).next;
    int i = 0;
    while (i != index -1)
    {
        p = (*p).next;
        q = (*q).next;
        i = i + 1;
    }
    if ((*q).next != a)
    {
        (*p).next=(*q).next;
    }
    else{
        (*p).next=a;
    }
    free(q);
    return a;
}
int main(void)
{
    // Craeting the head node with all the other nodes.
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
    (*head).data = 12;
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

    // Linking the fifth node with the sixth node.
    (*fifth).data = 40;
    (*fifth).next = sixth;

    // Linking the sixth node with the head node.
    (*sixth).data = 4;
    (*sixth).next = head;
    traversal_linkedlist(head);

    // Deletion at the begining.
    head = deletionat_start(head);
    printf("The linked list after deletion is looked like :\n");
    traversal_linkedlist(head);

    // Deletion at the end.
    head = deletionat_end(head);
    printf("The linked list after deletion is looked like :\n");
    traversal_linkedlist(head);

    // Deletion at the particular position.
    int ind;
    printf("Enter the index at which you want to delete the element :\n");
    scanf("%d", &ind);
    head = deletionat_index(head, ind);
    printf("The linked list after deletion is looked like :\n");
    traversal_linkedlist(head);

    return 0;
}