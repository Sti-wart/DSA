#include<stdio.h>

int n;
int graph[100][100];
int visited[10];

void bfs(int src)
{
    int q[100],front=0,rear=-1;
    int distance[10]={0};
    
    q[++rear] = src;
    visited[src]=1;

    printf("the bfs from %d is : ",src);
    while(front<=rear)
    {
        int u = q[front++];
        printf("%d ",u);

        for(int v=0;v<n;v++)
        {
            if(visited[v]==0 && graph[u][v]==1)
            {
                distance[v] = distance[u]+1;
                q[++rear]=v;
                visited[v]=1;
            }
        }
    }
    printf("\n");
    for(int i=0;i<n;i++)
        printf("shortest distance from %d to %d is %d units\n",src,i,distance[i]);
}

int main()
{
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("Enter the graph data martrix \n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    bfs(0);
    return 0;
}

/*
output
Enter the number of vertices : 4
Enter the graph data martrix 
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
the bfs from 0 is : 0 1 2 3 
shortest distance from 0 to 0 is 0 units
shortest distance from 0 to 1 is 1 units
shortest distance from 0 to 2 is 1 units
shortest distance from 0 to 3 is 2 units
*/