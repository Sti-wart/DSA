#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int countNodes(struct node* root)
{
    if(root==NULL)
        return 0;

    return (1 + countNodes(root->left)+countNodes(root->right) );
}

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

int main()
{
    printf("Enter the nodes into tree : ");
    struct node* root = build_tree();
    printf("The number of nodes in the given binary tree is %d",countNodes(root));
    
    return 0;
}