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

void search(struct node* root, int key)
{
    if(root==NULL)
    {
        printf("The key is not found in BST\n");
        return;
    }

    if(key==root->data)
    {
        printf("The key is found in BST");
        return;
    }
    else if(key<root->data)
        search(root->left,key);
    else
        search(root->right,key);
    
}

int main()
{
    int key;
    printf("Enter the nodes into tree : ");
    struct node* root = NULL;
    root = build_tree(root);
    printf("Enter the key to be searched : ");
    scanf("%d",&key);
    search(root,key);

    return 0;
}