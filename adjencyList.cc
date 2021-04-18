#include <cstdio>
#include <cstdlib>

typedef struct ListNode
{
    int vertexNode;
    struct ListNode *next;
} ListNode;

typedef struct Graph
{
    int V;
    int E;
    ListNode *point;
} Graph;

template <typename T>
T *adjacencygraph(T *G)
{
    int numV = 0, numE = 0;
    printf("Enter the number of Vertex: ");
    scanf("%d", &G->V);
    printf("Enter the number of Edges: ");
    scanf("%d", &G->E);

    ListNode *temp;
    G->point = (ListNode *)malloc(G->V * sizeof(ListNode));

    int i = 0;
    for (i = 0; i < G->V; i++)
    {
        (i[G->point]).vertexNode = i;
        (i[G->point]).next = NULL;
    }

    int x, y;
    for (i = 0; i < G->E; i++)
    {
        printf("Enter the source: ");
        scanf("%d", &x);
        printf("Enter the destination: ");
        scanf("%d", &y);

        temp = (ListNode *)malloc(sizeof(ListNode));
        temp->vertexNode = y;
        temp->next = NULL;

        ListNode *t = &G->point[x];
        while (t->next != NULL)
            t = t->next;

        t->next = temp;
    }
    return G;
}

template <typename T>
void printadjList(T *G)
{
    int i;
    ListNode *p;
    for (i = 0; i < G->V; i++)
    {
        *p = i[G->point];
        printf("%d -> ", (i[G->point]).vertexNode);
        while (p->next != NULL)
        {
            p = p->next;
            printf("%d -> ", p->vertexNode);
        }
        printf("NULL\n");
    }
}

/*Driver code*/
int main(int argc, char const *argv[])
{
    Graph *G = (Graph *)malloc(sizeof(Graph));
    if (!G) /*Checking memory allocation status.*/
    {
        printf("Memory allocation of graph is failed !\n");
    }
    G = adjacencygraph(G); /*Taking Graph Data Input from user*/
    printf("\n\n");
    printadjList(G);  /*Printing the Adjacency List for Graph Representation*/
    free(G); /*Securing memory leakage.*/
    return 0;
}
