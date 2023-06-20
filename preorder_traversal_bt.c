#include <stdio.h>
#include <stdlib.h>
// Program for Preorder traversal method of a binary tree.
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create_node(int data)
{
    struct node *x;
    x = (struct node *)malloc(sizeof(struct node));
    (*x).data = data;
    (*x).left = NULL;
    (*x).right = NULL;
    return x;
}
void preorder_traversal(struct node *a)
{
    if (a != NULL)
    {
        printf("%d\t", a->data);
        preorder_traversal(a->left);
        preorder_traversal(a->right);
    }
}
int main(void)
{

    // Constructing the root node of the tree.
    struct node *r;
    r = create_node(4);
    // Constructing the left child node of the root node.
    struct node *r1;
    r1 = create_node(1);
    // Constructing the right child node of the root node.
    struct node *r2;
    r2 = create_node(6);
    // Constructing the left child node of the root's left child node.
    struct node *r3;
    r3 = create_node(5);
    // Constructing the right child node of the root's left child node.
    struct node *r4;
    r4 = create_node(2);

    // Linking the root node with it's left child node and right child node and left child of the root node with it's family and so on.....
    (*r).left = r1;
    (*r).right = r2;
    (*r1).left = r3;
    (*r1).right = r4;

    preorder_traversal(r);

    return 0;
}