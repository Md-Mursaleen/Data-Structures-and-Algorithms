#include <stdio.h>
#include <stdlib.h>
// Program to make a BST (Binary Search Tree) and how to check wheather it is a BST or not.
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
int is_BST(struct node *p)
{
    static struct node *prev = NULL;
    if (p != NULL)
    {
        if (!is_BST((*p).left))
        {
            return 0;
        }
        if (prev != NULL && (*p).data <= (*prev).data)
        {
            return 0;
        }
        prev = p;
        return is_BST((*p).right);
    }
    else
    {
        return 1;
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

    // Inorder traversal of the above BST is:
    inorder_traversal(r);

    //Checking that a BT is BST or not.
    if (is_BST(r) == 1)
    {
        printf("\nThe given tree is Binary Search Tree.");
    }
    else
    {
        printf("\nThe given tree is not a Binary Search Tree.");
    }

    return 0;
}