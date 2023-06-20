#include <stdio.h>
#include <stdlib.h>
// Sorting and Searching in the Singly Linked List.
struct node
{
    int data;
    struct node *next;
};
// Traversal method in the Singly Linked List.
void traversal_linkedlist(struct node *a)
{
    printf("The elements in the linked list is :\n");
    while (a != NULL)
    {
        printf("%d\n", (*a).data);
        a = (*a).next;
    }
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
        while ((*r).next != NULL)
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
void search_linkedlist(struct node *a, int val)
{
    struct node *p = a;
    int i = -1;
    int flag = 0;
    while ((*p).next != NULL)
    {
        i++;
        if ((*p).data == val)
        {
            flag = 1;
            break;
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
    (*head).data = 7;
    (*head).next = second;

    // Linking the second node with the third node.
    (*second).data = 12;
    (*second).next = third;

    // Linking the third node with the fourth node.
    (*third).data = 44;
    (*third).next = fourth;

    // Linking the fourth node with the fifth node.
    (*fourth).data = 30;
    (*fourth).next = fifth;

    // Linking the fifth node with the NULL node.
    (*fifth).data = 4;
    (*fifth).next = NULL;
    traversal_linkedlist(head);

    // Sorting the given Singly Linked List.
    int len;
    len = 5;
    sorting_linkedlist(head, len);
    printf("After Sorting ");
    traversal_linkedlist(head);

    // Searching an element in the Singly Linked List.
    int val;
    printf("Enter the value that you want to search in the linked list :\n");
    scanf("%d", &val);
    search_linkedlist(head, val);

    return 0;
}