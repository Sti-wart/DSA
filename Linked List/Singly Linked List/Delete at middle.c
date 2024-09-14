#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_at_head(struct node**);
struct node* create_node();
void show_list(struct node*);
void delete_at_middle(struct node**,int);

int main()
{
    int n;
    struct node *head = NULL;
    printf("Enter the number of linked list : ");
    scanf("%d",&n);
    printf("Enter the linked list elements : ");
    for(int i=0;i<n;i++)
        insert_at_head(&head);

    show_list(head);
    printf("\nEnter the node position to be deleted : ");
    int pos;
    scanf("%d",&pos);
    delete_at_middle(&head,pos);
    show_list(head);

    return 0;
}

void delete_at_middle(struct node** head, int pos)
{
    struct node* temp = *head;
    struct node* prev = NULL;
    while(temp!=NULL && pos--)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next = temp->next;
    free(temp);
    
    return;
}

void insert_at_head(struct node** head)
{
    struct node* node = create_node();
    if(*head==NULL)
    {
        *head=node;
        return;
    }
    node->next = *head;
    *head = node;
    return;
}

struct node* create_node()
{
    int data;
    scanf("%d",&data);
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void show_list(struct node* head)
{
    while (head!=NULL)
    {
        printf("%d-->",head->data);
        head = head->next;
    }
    return;
}