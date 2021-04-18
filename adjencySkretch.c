#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int vertexNum;
    struct ListNode *next;
};

struct Graph
{
    int V;
    int E;
    struct ListNode *Adj;
};

struct Graph *adjcancylist()
{
    int i, x, y;
    struct ListNode *temp;

    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    printf("Enter the number of vertex and edges :");
    scanf("%d%d", &G->V, &G->E);
    G->Adj = (struct ListNode *)calloc(G->V, sizeof(struct ListNode));

    for (i = 0; i < G->V; i++)
    {
        G->Adj[i].next = i;
    }

    // return (G);
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
