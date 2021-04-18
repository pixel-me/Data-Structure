#include <cstdio>
#include <cstdlib>
#define inf 1e7

typedef struct Graph
{
    int V, E;
    int *p;
} Graph;

template <typename T>
T *adjencyMatrix(T *G)
{
    printf("Enter the number of Vertex: ");
    scanf("%d", &G->V);
    printf("Enter the number of Edges: ");
    scanf("%d", &G->E);

    G->p = (int *)malloc(G->V * G->V * sizeof(int));

    printf("Please enter a square matrix: \n\n");
    int i, j;
    for (i = 0; i < G->V; i++)
    {
        for (j = 0; j < G->V; j++)
        {
            printf("Enter %dx%d: ", i, j);
            scanf("%d", &(*(G->p + i * G->V + j)));
        }
    }

    return G;
}

template <typename T>
void printGraphMatrix(T *G)
{
    int i, j;
    for (i = 0; i < G->V; i++)
    {
        for (j = 0; j < G->V; j++)
        {
            if (*(G->p + i * G->V + j) == 1000)
            {
                printf("%7s", "inf");
            }
            else
            {
                printf("%7d", (*(G->p + i * G->V + j)));
            }
        }
        printf("\n");
    }
}

template <typename T>
void floydWarshall(T *G)
{
    int i, j, k;
    int *dist = (int *)malloc(G->V * G->V * sizeof(int));

    for (i = 0; i < G->V; i++)
    {
        for (j = 0; j < G->V; j++)
        {
            *(dist + i * G->V + j) = *(G->p + i * G->V + j);
        }
    }

    for (k = 0; k < G->V; k++)
    {
        for (i = 0; i < G->V; i++)
        {
            for (j = 0; j < G->V; j++)
            {
                if (*(dist + i * G->V + k) + *(dist + k * G->V + j) < *(dist + i * G->V + j))
                {
                    *(dist + i * G->V + j) = (*(dist + i * G->V + k) + *(dist + k * G->V + j));
                }
            }
        }
    }

    for (i = 0; i < G->V; i++)
    {
        for (j = 0; j < G->V; j++)
        {
            *(G->p + i * G->V + j) = *(dist + i * G->V + j);
        }
    }
    free(dist);
}

/*Driver code*/
int main(int argc, char const *argv[])
{
    Graph *G = (Graph *)malloc(sizeof(Graph));
    if (!G)
    {
        printf("Memory allocation of graph is failed !\n");
    }

    G = adjencyMatrix(G);
    printf("\n\n");

    printGraphMatrix(G);

    floydWarshall(G);

    printf("\n\n");
    printGraphMatrix(G);

    free(G);
    return 0;
}
