#include<stdio.h>

typedef struct edge{
    int src,dest;
}EDGE;

int n,e;
int graph[10][10];
int head[10];
EDGE edge[10];

int find(int i)
{
    if(head[i] == -1)
        return i;
    return find(head[i]);
}

void _union(int x, int y)
{
    head[x]=y;
}

int main()
{    
    int hasCycle = 0;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("Enter the number of edges : ");
    scanf("%d",&e);
    printf("Enter the edges : ");
    for(int i=0;i<e;i++){
        scanf("%d %d",&edge[i].src,&edge[i].dest);        
    }
    
    for(int i=0;i<n;i++)
        head[i]= -1;

    for(int i=0;i<e;i++)
    {
        int x = find(edge[i].src);
        int y = find(edge[i].dest);

        if(x==y)
        {
            hasCycle =1;
            break;
        }
        _union(x,y);
    }

    if(hasCycle)
        printf("cycle is present");
    else 
        printf("cycle is not present");

    return 0;
}

/*
output
Enter the number of vertices : 4
Enter the number of edges : 3
Enter the edges : 0 1
0 2
1 3
cycle is not present

output
Enter the number of vertices : 4
Enter the number of edges : 4
Enter the edges : 0 1
0 2
1 2
1 3
cycle is present
*/