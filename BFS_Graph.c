#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *getnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void push(int data)
{
    printf("Push called\n");
    node *temp = getnode(data);
    if (!head)
    {
        head = temp;
        return;
    }
    node *ptr = head;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

int front()
{
    printf("front called\n");
    if (!head)
    {
        return 0; // return NULL;
    }
    node *ptr = head;
    return (ptr->data);
}

void pop()
{
    printf("pop called\n");
    if (!head)
    {
        printf("\nError: Underflow\n\n");
        return;
    }
    node *ptr = head;
    head = head->next;
    free(ptr);
}
int isEmpty()
{
    printf("is Empty called\n");
    if (!head)
    {
        return 1;
    }
    return 0;
}
// void marker(int v)
// {
//     f = (int *)calloc(v, sizeof(int));
//     for (int i = 0; i < v; i++)
//     {
//         f[i] = 0; // Resetting the marker ...
//     }
// }
// int ismarked(int l)
// {
//     if (!f[l])
//     {
//         return 0;
//     }
//     return 1;
// }
// void markit(int l)
// {
//     f[l] = 1;
// }


int main(int argc, char const *argv[])
{
    int v, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("\nEnter the number of edges: ");
    scanf("%d", &e);
    int matrix[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            matrix[i][j] = 0; // Resetting the matrix...
        }
    }
    for (int i = 1; i <= e; i++)
    {
        int s, d, c;
        printf("\nFrom: ");
        scanf("%d", &s);
        printf("To: ");
        scanf("%d", &d);
        printf("Enter the cost of edge from %d to %d: ", s, d);
        scanf("%d", &c);
        printf("\n\nEdge between %d and %d with cost %d is successfully combined..\n\n", s, d, c);
        // *(matrix + (s - 1) * v + (d - 1)) = c;
        matrix[s - 1][d - 1] = c;
        // *(matrix + (d - 1) * v + (s - 1)) = c;
        matrix[d - 1][s - 1] = c;
    }
    // printAdjmatrix(v, matrix);

    printf("\nAdjacency matrix...\n\n|");
    for (int i = 1; i <= v; i++)
    {
        printf("   %d", i);
    }
    printf("\n");
    for (int i = 0; i < v + 2; i++)
    {
        printf("----");
    }
    printf("\n");
    for (int i = 0; i < v; i++, printf("\n"))
    {
        printf("%d  |", (i + 1));
        for (int j = 0; j < v; j++)
        {
            printf("%d   ", matrix[i][j]);
        }
    }
////////////////////////////////////////////////////////////////////////////////
    int *f = (int *)calloc(v, sizeof(int));
    for (int i = 0; i < v; i++)
    {
        f[i] = 0; // Resetting the marker ...
    }
    int val = 0;
    printf("BFS...in graph... \n");
    push(1); //matrix[0][0]
    f[0] = 1;
    printf("first value pushed f[0] = %d, matrix[0][0] = %d \n",f[0],matrix[0][0]);
    while (!isEmpty())
    {
        printf("Inside isEmpty while loop\n");
        val = front();
        printf("%d\t", val);
        pop();
        for (int j = 0; j < v; j++)
        {
            for (int i = 0; i < v; i++)
            {
                if (!matrix[j][i])
                {
                    f[j] = 1;
                    push(j);
                }
            }
        }
    }
    printf("\n");
    free(f);
    // free();
    return 0;
}
