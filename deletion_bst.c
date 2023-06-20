#include <stdio.h>
#include <malloc.h>
// Program to Delete an Element in a BST.
// ADT for a BST.
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
// Function to Create a New Node.
struct node *create_node(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    (*n).data = data;
    (*n).left = NULL;
    (*n).right = NULL;
    return n;
}
// Function to Find the Inorder Traversal of the given BST.
void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal((*root).left);
        printf("%d\t", (*root).data);
        inorder_traversal((*root).right);
    }
}
// Function to Find the Inorder Pre of the given Node.
struct node *inorderPre(struct node *a)
{
    a = (*a).left;
    while ((*a).right != NULL)
    {
        a = (*a).right;
    }
    return a;
}
// Function to Delete an Element in a BST.
struct node *deletion_BST(struct node *a, int key)
{
    if (a == NULL)
    {
        return NULL;
    }
    if ((*a).left == NULL && (*a).right == NULL)
    {
        free(a);
        return NULL;
    }
    struct node *inPre;
    if (key < (*a).data)
    {
        (*a).left = deletion_BST((*a).left, key);
    }
    else if (key > (*a).data)
    {
        (*a).right = deletion_BST((*a).right, key);
    }
    else
    {
        // Deletion startegy when the node is found.
        inPre = inorderPre(a);
        (*a).data = (*inPre).data;
        (*a).left = deletion_BST((*a).left, (*inPre).data);
    }
    return a;
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

    printf("\nThe elements in a BST before deletion is given as :");
    // Inorder traversal of the above BST before deletion is:
    inorder_traversal(r);

    // Calling the deletion function to delete an element in a BST.
    deletion_BST(r, 5);

    printf("\nThe elements in a BST after deletion is given as :");
    // Inorder traversal of the above BST after deletion is:
    inorder_traversal(r);

    return 0;
}