/*  ***********DS_&_Algo_0187cs191038_Lab_35*************  */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v, e, s, d, c;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("\nEnter the number of edges: ");
    scanf("%d", &e);
    int *matrix = (int *)calloc(v * v, sizeof(int));
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            *(matrix + i * v + j) = 0;
        }
    }
    printf("\nEnter the edges connection..\n");
    for (int i = 1; i <= e; i++)
    {
        printf("\nFrom: ");
        scanf("%d", &s);
        printf("To: ");
        scanf("%d", &d);
        printf("Enter the cost of edge from %d to %d: ", s, d);
        scanf("%d",&c);
        printf("\n\nEdge between %d and %d with cost %d is successfully combined..\n\n", s, d, c);
        *(matrix + (s - 1) * v + (d - 1)) = c;
        *(matrix + (d - 1) * v + (s - 1)) = c;
    }
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
            printf("%d   ", *(matrix + i * v + j));
        }
    }
    free(matrix);
    return 0;
}
