#include <stdio.h>
#include <stdlib.h>
// Program to search an element in a BST (Iterative Searching opeartion in a BST).
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create_node(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    (*n).data = data;
    (*n).left = NULL;
    (*n).right = NULL;
    return n;
}
void inorder_traversal(struct node *a)
{
    if (a != NULL)
    {
        inorder_traversal((*a).left);
        printf("%d\t", (*a).data);
        inorder_traversal((*a).right);
    }
}
struct node *iterate_search_BST(struct node *a, int key)
{
    while (a != NULL)
    {
        if ((*a).data == key)
        {
            return a;
        }
        else if ((*a).data > key)
        {
            a = (*a).left;
        }
        else
        {
            a = (*a).right;
        }
    }
    return NULL;
}
int main(void)
{
    // Create a root node.
    struct node *r;
    r = create_node(5);

    // Create a left sub tree's root node.
    struct node *r1;
    r1 = create_node(3);

    // Create a right sub tree's root node.
    struct node *r2;
    r2 = create_node(6);

    struct node *r3;
    r3 = create_node(1);

    struct node *r4;
    r4 = create_node(4);

    // Linking all the nodes with each other so that a BT becomes a BST.
    (*r).left = r1;
    (*r).right = r2;
    (*r1).left = r3;
    (*r1).right = r4;

    // Inorder traversal of the above BST is:
    inorder_traversal(r);

    // Iterative Searching of the above BST is:
    int key;
    printf("\nEnter the element that you want to search in this BST : ");
    scanf("%d", &key);

    struct node *n = iterate_search_BST(r, key);
    if (n != NULL)
    {
        printf("\nThe element %d is found in this BST", (*n).data);
    }
    else
    {
        printf("\nThe element is not found in this BST");
    }

    return 0;
}