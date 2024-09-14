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

struct node* delete_node(struct node* root, int data)
{
    if(root==NULL)
        return NULL;

    if(data < root->data){
        root->left = delete_node(root->left,data);
    }
    else if(data==root->data)
    {
        // node with 0 children
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        // node with 1 child
        else if(root->left!=NULL && root->right==NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        // node with 2 children
        else{
            struct node* replace = root->right;
            while(replace->left!=NULL)
                replace = replace->left;

            root->data = replace->data;
            delete_node(root->right,replace->data);
        }
    }
    else{
        root->right = delete_node(root->right,data);
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
    printf("Breadth First traversal before deletion\n");
    bfs(root);

    int value;
    printf("Enter the data to be deleted : ");
    scanf("%d",&value);
    root = delete_node(root,value);

    printf("Breadth First traversal after deletion\n");
    bfs(root);

    return 0;
}