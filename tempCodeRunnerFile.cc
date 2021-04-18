int i, j, k;
    int dist[G->V][G->V];

    for (i = 0; i < G->V; i++)
    {
        for (j = 0; j < G->V; j++)
        {
            dist[i][j] = *(G->p + i * G->V + j);
        }
    }

    for (k = 0; k < G->V; k++)
    {
        for (i = 0; i < G->V; i++)
        {
            for (j = 0; j < G->V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = (dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (i = 0; i < G->V; i++)
    {
        for (j = 0; j < G->V; j++)
        {
            *(G->p + i * G->V + j) = dist[i][j];
        }
    }