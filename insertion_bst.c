#include <stdio.h>
#include <malloc.h>
// Program to insert an element in a BST.
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
void insertion_BST(struct node *a, int key)
{
    struct node *prev;
    while (a != NULL)
    {
        prev = a;
        if (key == (*a).data)
        {
            return;
        }
        else if (key < (*a).data)
        {
            a = (*a).left;
        }
        else
        {
            a = (*a).right;
        }
    }
    struct node *new = create_node(key);
    if (key < (*prev).data)
    {
        (*prev).left = new;
    }
    else
    {
        (*prev).right = new;
    }
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

    printf("\nThe elements in a BST before insertion is given as :");
    // Inorder traversal of the above BST before insertion is:
    inorder_traversal(r);

    // Calling the insertion function to insert an element in a BST.
    insertion_BST(r, 2);

    printf("\nThe elements in a BST after insertion is given as :");
    // Inorder traversal of the above BST after insertion is:
    inorder_traversal(r);

    return 0;
}