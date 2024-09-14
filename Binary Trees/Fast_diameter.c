#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct pair
{
    int height;
    int diameter;
};

struct pair diameter(struct node* root)
{
    struct pair p;

    if(root==NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }

    struct pair op1 = diameter(root->left);
    struct pair op2 = diameter(root->right);

    int h = op1.height + op2.height;
    int maxDia = op1.diameter>op2.diameter ? op1.diameter:op2.diameter;
    maxDia = h>maxDia ? h:maxDia;

    p.diameter = maxDia;
    p.height = 1 + (op1.height>op2.height ? op1.height:op2.height); 
    return p;
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
    struct pair p = diameter(root);
    printf("Diameter of the tree is %d",p.diameter);

    return 0;
}