#include <stdio.h>
// Linked Representation of a Binary Tree.
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
    (*n).data = 2;
    (*n).left = NULL;
    (*n).right = NULL;
    return n;
}
int main(void)
{

    // //Constructing the root node of the tree.
    // struct node *root_node;
    // root_node=(struct node *)malloc(sizeof(struct node));
    // (*root_node).data=2;
    // (*root_node).left=NULL;
    // (*root_node).right=NULL;

    // //Constructing the left child node of the root node.
    // struct node *left_node;
    // left_node=(struct node *)malloc(sizeof(struct node));
    // (*left_node).data=12;
    // (*left_node).left=NULL;
    // (*left_node).right=NULL;

    // //Constructing the right child node of the root node.
    // struct node *right_node;
    // right_node=(struct node *)malloc(sizeof(struct node));
    // (*right_node).data=4;
    // (*right_node).left=NULL;
    // (*right_node).right=NULL;

    // //Constructing the root node of the tree.
    struct node *root_node;
    root_node = create_node(2);

    // //Constructing the left child node of the root node.
    struct node *left_node;
    left_node = create_node(12);

    // //Constructing the right child node of the root node.
    struct node *right_node;
    right_node = create_node(4);

    //Linking the root node with its left and right child node.
    (*root_node).left=left_node;
    (*root_node).right=right_node;


    return 0;
}