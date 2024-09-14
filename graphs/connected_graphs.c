#include<stdio.h>

int n;
int graph[100][100];
int visited[10];

void bfs(int src)
{
    int q[100],front=0,rear=-1;

    q[++rear] = src;;
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
                q[++rear]=v;
                visited[v]=1;
            }
        }
    }
    printf("\n");
}


void check_connected(){
    int unconnected_graphs = 0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            bfs(i);
            unconnected_graphs++;
        }
    }
    printf("\nWe have %d unconnected graphs",unconnected_graphs);
}


int main()
{
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("Enter the graph data martrix \n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    check_connected();
    return 0;
}

/*
output
Enter the number of vertices : 7
Enter the graph data martrix 
0 0 1 0 1 0 0
0 0 0 1 0 0 1
1 0 0 0 0 0 0
0 1 0 0 0 0 1
1 0 0 0 0 0 0
0 0 0 0 0 0 0  
0 0 0 1 0 0 0
the bfs from 0 is : 0 2 4 
the bfs from 1 is : 1 3 6
the bfs from 5 is : 5

We have 3 unconnected graphs
*/