#include <stdio.h>
#include <stdlib.h>
// All the Insertion Operations in the Circular Linked List.
// ADT for Circular Linked List
struct node
{
    int data;
    struct node *next;
};
// Function to Find the Traversal of the Circular Linked List.
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
// Function to Insert an Element At Begining of the Circular Linked List.
struct node *insertionat_start(struct node *a, int data)
{
    struct node *b;
    b = (struct node *)malloc(sizeof(struct node));
    (*b).data = data;
    struct node *p = (*a).next;
    while ((*p).next != a)
    {
        p = (*p).next;
    }
    (*b).next = a;
    (*p).next = b;
    return b;
}
// Function to Insert an Element At end of the Circular Linked List.
struct node *insertionat_end(struct node *a, int data)
{
    struct node *c;
    c = (struct node *)malloc(sizeof(struct node));
    (*c).data = data;
    struct node *p = (*a).next;
    while ((*p).next != a)
    {
        p = (*p).next;
    }
    (*p).next = c;
    (*c).next = a;
    return a;
}
// Function to Insert an Element At Any Position of the Circular Linked List.
struct node *insertionat_index(struct node *a, int data, int index)
{
    struct node *d;
    d = (struct node *)malloc(sizeof(struct node));
    (*d).data = data;
    struct node *p = a;
    int i = 0;
    while (i != index - 1)
    {
        p = (*p).next;
        i = i + 1;
    }

    (*d).next = (*p).next;
    (*p).next = d;
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

    // Allocating the heap memory to each node.
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

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

    // Linking the fifth node with the head node.
    (*fifth).data = 40;
    (*fifth).next = head;
    traversal_linkedlist(head);

    // Insertion at the begining.
    int m;
    printf("Enter the data that you want to insert at the beginning :\n");
    scanf("%d", &m);
    head = insertionat_start(head, m);
    printf("The linked list after insertion is looked like :\n");
    traversal_linkedlist(head);

    // Insertion at the end.
    int n;
    printf("Enter the data that you want to insert at the end :\n");
    scanf("%d", &n);
    head = insertionat_end(head, n);
    printf("The linked list after insertion is looked like :\n");
    traversal_linkedlist(head);

    // Insertion at the particular position.
    int ind;
    printf("Enter the index at which you want to insert an element :\n");
    scanf("%d", &ind);

    int j;
    printf("Enter the element that you want to insert at this index :\n");
    scanf("%d", &j);
    head = insertionat_index(head, j, ind);
    traversal_linkedlist(head);

    return 0;
}