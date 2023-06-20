#include <stdio.h>
#include <stdlib.h>
// Sorting and Searching in the Circular Linked List.
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
void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
void sorting_linkedlist(struct node *a, int l)
{
    int i = 1;
    while (i <= l)
    {
        struct node *p = a;
        struct node *q = (*p).next;
        struct node *r = a;
        while ((*r).next != a)
        {
            if ((*p).data > (*q).data)
            {
                swap(&(*p).data, &(*q).data);
            }
            p = (*p).next;
            q = (*q).next;
            r = (*r).next;
        }
        i++;
    }
}
int search_linkedlist(struct node *a, int val)
{
    struct node *p = a;
    int i = -1;
    int flag = 0;
    while ((*p).next != a)
    {
        i++;
        if ((*p).data == val)
        {
            flag = 1;
        }
        p = (*p).next;
    }
    if (flag == 0)
    {
        printf("The element is not found");
    }
    else
    {
        printf("The element is found at the index %d", i);
    }
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
    (*head).data = 67;
    (*head).next = second;

    // Linking the second node with the third node.
    (*second).data = 12;
    (*second).next = third;

    // Linking the third node with the fourth node.
    (*third).data = 21;
    (*third).next = fourth;

    // Linking the fourth node with the fifth node.
    (*fourth).data = 35;
    (*fourth).next = fifth;

    // Linking the fifth node with the head node.
    (*fifth).data = 4;
    (*fifth).next = head;
    traversal_linkedlist(head);

    int len;
    len = 5;
    sorting_linkedlist(head, len);
    printf("After Sorting ");
    traversal_linkedlist(head);

    // Searching an element in the Circular Linked List.
    int val;
    printf("Enter the value that you want to search in the linked list :\n");
    scanf("%d", &val);
    search_linkedlist(head, val);

    return 0;
}