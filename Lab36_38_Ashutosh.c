/*  ***********DS_&_Algo_0187cs191038_Lab_36*************  */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct graph
{
    int v, e, *m;
    struct node **adj;
} graph;
//////////////////////////////////////////////////////////////////////////
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
    // printf("Push called\n");
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
    // printf("front called\n");
    if (!head)
    {
        return 0; // return NULL;
    }
    node *ptr = head;
    return (ptr->data);
}

void pop()
{
    // printf("pop called\n");
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
    // printf("is Empty called\n");
    if (!head)
    {
        return 1;
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////

node *getNode()
{
    struct node *newNode = malloc(sizeof(node));
    newNode->data = 0;
    newNode->next = NULL;
    return newNode;
}

graph *getgraph(int v, int e)
{
    graph *g = malloc(sizeof(graph));
    ;
    g->v = v;
    g->e = e;
    g->m = malloc(v * sizeof(int));
    g->adj = malloc(v * sizeof(node));
    for (int i = 0; i < v; i++)
    {
        g->adj[i] = NULL;
        g->m[i] = 0;
    }
    return g;
}

void addEdge(graph *g, int s, int d)
{
    node *newNode = getNode();
    newNode->data = d;
    newNode->next = g->adj[s];
    g->adj[s] = newNode;
    newNode = getNode();
    newNode->data = s;
    newNode->next = g->adj[d];
    g->adj[d] = newNode;
}

void bfs(graph *graph, int anyvertex)
{

    graph->m[anyvertex] = 1;
    push(anyvertex);

    while (!isEmpty())
    {
        int val = front();
        pop();
        printf("%d\t ", val);

        struct node *temp = graph->adj[val];

        while (temp)
        {
            int adjoint = temp->data;

            if (graph->m[adjoint] == 0)
            {
                graph->m[adjoint] = 1;
                push(adjoint);
            }
            temp = temp->next;
        }
    }
}

void dfs(graph *g, int v)
{
    node *ptr = g->adj[v];
    node *temp = ptr;
    g->m[v] = 1;
    printf("%d\t", v);
    while (temp != NULL)
    {
        int connectedVertex = temp->data;

        if (g->m[connectedVertex] == 0)
        {
            dfs(g, connectedVertex);
        }
        temp = temp->next;
    }
}

int menu()
{
    int c;
    printf("enter 1 for print Adjlist...\n\n");
    printf("enter 2 for print bfs...\n\n");
    printf("enter 3 for print dfs...\n\n");
    scanf("%d", &c);
    return c;
}

int main(int argc, char const *argv[])
{
    int v, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("\nEnter the number of edges: ");
    scanf("%d", &e);
    graph *g = getgraph(v, e);
    int s, d, c, f = 1;
    for (int i = 0; i < g->e; i++)
    {
        printf("Enter the source vertes: ");
        scanf("%d", &s);
        if (f)
        {
            c = s;
            --f;
        }
        printf("Enter the target vertex: ");
        scanf("%d", &d);
        addEdge(g, s, d);
    }
    int a = 0;
    switch (menu())
    {
    case 1:
        /* code */
        break;
    case 2:
        bfs(g, c);
        break;
    case 3:
        printf("Please select one of the method: \n\nEnter 1 for recursion or 0 for iteration: ");
        scanf("%d", &a);
        if (a)
        {
            dfs(g, c);
        }
        else
        {
            printf("Nothing implement\n");
        }
        break;
    default:
        printf("Invalid choice.\n");
        break;
    }
    printf("\n");
    return 0;
}
