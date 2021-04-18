#include <stdio.h>

int parent[10];

int find(int i)
{
    while(parent[i])
    {
        i=parent[i];
    }
    return i;
}

int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}

int main(void) 
{
    int cost[10][10],u,v,i,j,min,mincost=0,n,ne=1,a,b;
    printf("Enter no. of vertices: ");
    scanf("%d",&n);

    printf("Enter Adjacency Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }

    while(ne<n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }

        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            printf("\n%d edge(%d -> %d)=%d",ne++,a,b,min);
            mincost += min;
        }
        cost[a][b]=cost[b][a]=999;
    }

    printf("\nMin. cost of spanning tree=%d",mincost);

    return 0;
}
