// build a balance from an array

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node()
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* build_balance_tree(int *a, int s, int e)
{
    if(s>e)
        return NULL;

    int mid  = (s+e)/2;
    struct node* root = create_node();
    
    root->data = a[mid];
    root->left = build_balance_tree(a,s,mid-1);
    root->right = build_balance_tree(a,mid+1,e);
    return root;
}

void bfs(struct node* root)
{
    struct node* q[20];
    int front=0,rear=-1;

    q[++rear] = root;
    q[++rear] = NULL;

    while(front<=rear)
    {
        if(q[front]==NULL)
        {
            if(front<rear)
                q[++rear]=NULL;

            front++;
            printf("\n");
        }
        else
        {
            struct node* cur = q[front++];
            printf("%d ",cur->data);

            if(cur->left)
                q[++rear] = cur->left;

            if(cur->right)
                q[++rear] = cur->right;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the nodes into tree : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct node* root = build_balance_tree(arr,0,n-1);
    printf("Balance Tree is as follows\n");
    bfs(root);

    return 0;
}