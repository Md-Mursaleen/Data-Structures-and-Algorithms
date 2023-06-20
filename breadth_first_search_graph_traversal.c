#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f, r;
    int *arr;
};
int isEmpty(struct queue *a)
{
    if ((*a).f == (*a).r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct queue *a)
{
    if ((*a).r == (*a).size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int enqueue(struct queue *a, int val)
{
    if (isFull(a))
    {
        printf("The Queue is full that means queue is overflow,you cannot add more element in it.\n");
        return 1;
    }
    else
    {
        (*a).r++;
        (*a).arr[(*a).r] = val;
    }
}
int dequeue(struct queue *a)
{
    if (isEmpty(a))
    {
        printf("The Queue is empty that means queue is underflow,you cannot remove more element from it.\n");
        return 1;
    }
    else
    {
        (*a).f++;
        int val = (*a).arr[(*a).f];
        return val;
    }
}
int main(void)
{
    struct queue ptr;
    ptr.size = 70;
    ptr.f = ptr.r = 0;
    ptr.arr = (int *)malloc(ptr.size * sizeof(int));

    // BFS implementation
    int i = 0;                               // source node here is 0 that means traversal is starting from 0 node onwards.
    int vertices[7] = {0, 0, 0, 0, 0, 0, 0}; // it is used to track which node is visited or which is not.
    int adjacency_matrix[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}

    };
    printf("%d,", i);
    vertices[i] = 1;
    enqueue(&ptr, i); // enqueue i for exploration.
    while (!isEmpty(&ptr))
    {
        int node = dequeue(&ptr);
        for (int j = 0; j < 7; j = j + 1)
        {
            if (adjacency_matrix[node][j] == 1 && vertices[j] == 0)
            {
                printf("%d,", j);
                vertices[j]=1;
                enqueue(&ptr,j);
            }
        }
    }

    return 0;
}