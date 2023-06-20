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
struct node *insertionat_start(struct node *a, int data)
{
    struct node *b;
    b = (struct node *)malloc(sizeof(struct node));
    (*b).data = data;
    (*b).next = a;
    (*a).prev = b;
    return b;
}
struct node *insertionat_index(struct node *a, int data, int index)
{
    struct node *c;
    c = (struct node *)malloc(sizeof(struct node));
    struct node *p = a;
    int i = 0;
    while (i != index - 1)
    {
        p = (*p).next;
        i = i + 1;
    }
    (*c).data = data;
    (*c).next=(*p).next;
    (*p).next = c;
    (*c).prev = p;
    return a;
}
struct node *insertionat_end(struct node *a, int data)
{
    struct node *d;
    d = (struct node *)malloc(sizeof(struct node));
    struct node *p = a;
    while ((*p).next != NULL)
    {
        p = (*p).next;
    }
    (*d).data = data;
    (*p).next = d;
    (*d).prev = p;
    (*d).next = NULL;
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

    // Insertion at the begining.
    int i;
    printf("Enter the element that you want to insert at begining :\n");
    scanf("%d", &i);
    head_node = insertionat_start(head_node, i);
    traversallinked_list(head_node);

    // Insertion at the particular position.
    int ind;
    printf("Enter the index at which you want to insert an element :\n");
    scanf("%d", &ind);

    int j;
    printf("Enter the element that you want to insert at this index :\n");
    scanf("%d", &j);
    head_node = insertionat_index(head_node, j, ind);
    traversallinked_list(head_node);

    // Insertion at the end.
    int k;
    printf("Enter the element that you want to insert at end :\n");
    scanf("%d", &k);
    head_node = insertionat_end(head_node, k);
    traversallinked_list(head_node);

    return 0;
}