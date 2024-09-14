#include<stdio.h>

int n;
int graph[10][10];
int visited[10];

int detect_cycle(int src)
{
    int q[100],front=0,rear=-1;
    int parent[10];

    for(int i=0;i<n;i++)
        parent[i] = -1;

    q[++rear] = src;
    visited[src]=1;

    while(front<=rear)
    {
        int u = q[front++];

        for(int v=0;v<n;v++)
        {
            if(graph[u][v]==1)
            {
                if(visited[v]==0)
                {
                    parent[v]=u;
                    q[++rear]=v;
                    visited[v]=1;
                }
                else if(parent[u]!=v){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{    
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("Enter the graph data martrix \n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    int isCyclePresent = detect_cycle(0);
    if(isCyclePresent)
        printf("cycle is present");
    else
        printf("cycle is not present");

    return 0;
}