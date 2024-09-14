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

void postorder(struct node* root)
{
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main()
{
    printf("Enter the nodes into tree : ");
    struct node* root = build_tree();
    printf("Post order traversal is as follows\n");
    postorder(root);

    return 0;
}