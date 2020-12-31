#include <stdio.h>

int main()
{
    int v, e, s, d;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("\nEnter the number of edges: ");
    scanf("%d", &e);
    int matrix[v + 1][v + 1];
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            matrix[i][j] = 0;
        }
    }

    printf("\nEnter the edges connection..\n");
    for (int i = 1; i <= e; i++)
    {
        printf("\nFrom: ");
        scanf("%d", &s);
        printf("To: ");
        scanf("%d", &d);
        printf("\n\nEdge between %d and %d is successfully combined..\n\n", s, d);
        matrix[s][d] = 1;
        matrix[d][s] = 1;
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
    for (int i = 1; i <= v; i++, printf("\n\n"))
    {
        printf("%d  |", (i));
        for (int j = 1; j <= v; j++)
        {
            printf("%d   ", matrix[i][j]);
        }
    }
    return 0;
}
