#include<stdio.h>
#include<stdlib.h>

struct node
{
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

struct node* build_tree()
{
    int data;
    scanf("%d",&data);

    if(data==-1)
        return NULL;

    struct node* root = create_node();
    root->data = data;

    root->left = build_tree();
    root->right = build_tree();

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
    printf("Enter the nodes into tree : ");
    struct node* root = build_tree();
    printf("Breadth First traversal is as follows\n");
    bfs(root);

    return 0;
}