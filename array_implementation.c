#include <stdio.h>
#include <stdlib.h>
struct myArr
{
    int used_size;
    int total_size;
    int *ptr;
};
void allocate(struct myArr *a, int tsize, int usize)
{
    (*a).total_size = tsize;
    (*a).used_size = usize;
    (*a).ptr = (int *)malloc(tsize * sizeof(int));
}
void setArr(struct myArr *a)
{
    for (int i = 0; i < (*a).used_size; i = i + 1)
    {
        printf("Enter the elements in the array :\n");
        scanf("%d", &(*a).ptr[i]);
    }
}
void showArr(struct myArr *a)
{
    for (int i = 0; i < (*a).used_size; i = i + 1)
    {

        printf("%d\n", (*a).ptr[i]);
    }
}
int main(void)
{
    struct myArr marks;
    allocate(&marks, 10, 2);
    setArr(&marks);
    showArr(&marks);

    return 0;
}