#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert_BST(struct node* root, int value)
{
    if(root==NULL)
    {
        struct node* new_node = create_node();
        new_node->data = value;
        return new_node;
    }

    if(value<=root->data)
        root->left = insert_BST(root->left,value);
    else
        root->right = insert_BST(root->right,value);

    return root;
}

struct node* build_tree(struct node* root)
{
    int data;
    scanf("%d",&data);

    while(data!=-1)
    {
        root = insert_BST(root,data);
        scanf("%d",&data);
    }
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
                q[++rear] = NULL;
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
    struct node* root = NULL;
    root = build_tree(root);
    printf("Breadth First traversal is as follows\n");
    bfs(root);

    return 0;
}