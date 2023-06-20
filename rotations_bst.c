#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
int getHeight(struct node *a)
{
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        return (*a).height;
    }
}
struct node *create_node(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    (*n).data = data;
    (*n).left = NULL;
    (*n).right = NULL;
    (*n).height = 1;
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
int getB_F(struct node *a)
{
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        return getHeight((*a).left) - getHeight((*a).right);
    }
}
int max(int a, int b)
{
    return a > b ? a : b;
}
struct node *right_rotate(struct node *y)
{
    struct node *x = (*y).left;
    struct node *T2 = (*x).right;

    (*x).right = y;
    (*y).left = T2;

    (*x).height = max(getHeight((*x).left), getHeight((*x).right)) + 1;
    (*y).height = max(getHeight((*y).left), getHeight((*y).right)) + 1;
    return x;
}
struct node *left_rotate(struct node *x)
{
    struct node *y = (*x).right;
    struct node *T2 = (*y).left;

    (*y).left = x;
    (*x).right = T2;

    (*x).height = max(getHeight((*x).left), getHeight((*x).right)) + 1;
    (*y).height = max(getHeight((*y).left), getHeight((*y).right)) + 1;
    return y;
}
struct node *insertion_BST(struct node *a, int key)
{
    if (a == NULL)
    {
        return create_node(key);
    }
    if (key < (*a).data)
    {
        (*a).left = insertion_BST((*a).left, key);
    }
    else if (key > (*a).data)
    {
        (*a).right = insertion_BST((*a).right, key);
    }

    (*a).height = max(getHeight((*a).left), getHeight((*a).right)) + 1;
    int bf = getB_F(a);

    // LL Rotations
    if (bf > 1 && key < (*(*a).left).data)
    {
        return right_rotate(a);
    }
    // RR Rotations
    if (bf < -1 && key > (*(*a).right).data)
    {
        return left_rotate(a);
    }
    // LR Rotations
    if (bf > 1 && key > (*(*a).left).data)
    {
        (*a).left = left_rotate((*a).left);
        return right_rotate(a);
    }
    // RL Rotations
    if (bf < -1 && key < (*(*a).right).data)
    {
        (*a).right = right_rotate((*a).right);
        return left_rotate(a);
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

    printf("\nThe elements in a BST before insertion is given as :");
    // Inorder traversal of the above BST before insertion is:
    inorder_traversal(r);

    // Calling the insertion function to insert an element in a BST.
    r = insertion_BST(r, 2);
    r = insertion_BST(r, 12);
    r = insertion_BST(r, 62);
    r = insertion_BST(r, 90);
    r = insertion_BST(r, 44);

    printf("\nThe elements in a BST after insertion is given as :");
    // Inorder traversal of the above BST after insertion is:
    inorder_traversal(r);

    return 0;
}