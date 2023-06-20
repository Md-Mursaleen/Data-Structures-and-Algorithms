#include <stdio.h>
#include <stdlib.h>
// Sorting and Searching in the Doubly Linked List.
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
// Traversal method in the Doubly Linked List.
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
    (*fifth_node).data = 3;
    (*fifth_node).prev = fourth_node;
    (*fifth_node).next = NULL;
    traversal_linkedlist(head_node);

        // Sorting the given Doubly Linked List.
    int len;
    len = 5;
    sorting_linkedlist(head_node, len);
    printf("After Sorting ");
    traversal_linkedlist(head_node);

    // Searching an element in the Doubly Linked List.
    int val;
    printf("Enter the value that you want to search in the linked list :\n");
    scanf("%d", &val);
    search_linkedlist(head_node, val);

    return 0;
}