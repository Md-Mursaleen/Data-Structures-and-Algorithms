#include <stdio.h>
// DFS implementation
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
void DFS(int i)
{
    printf("%d,", i);
    vertices[i] = 1;
    for (int j = 0; j < 7; j = j + 1)
    {
        if (adjacency_matrix[i][j] == 1 && vertices[j] == 0)
        {
            DFS(j);
        }
    }
}
int main(void)
{
    //DFS(0);  //it represent the node with which i am going to start the traversal method.
    DFS(1);

    return 0;
}