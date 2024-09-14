#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_at_head(struct node **head);
void insert_at_middle(struct node **head);
struct node* create_node();
void show_list(struct node *head);

int main()
{
    int n;
    printf("Enter the number of linked list : ");
    scanf("%d",&n);

    struct node *head = NULL;
    printf("Enter the elements into linked list : ");
    for(int i=0;i<n;i++)
       insert_at_head(&head);

    show_list(head);
    insert_at_middle(&head);
    show_list(head);

    return 0;
}

void insert_at_head(struct node **head)
{
    struct node *node = create_node();
    if(*head==NULL)
    {
        *head=node;
        return;
    }
    node->next = *head;
    *head = node;
}

void insert_at_middle(struct node **head)
{
    int pos;
    printf("\nEnter the data to be inserted : ");
    struct node* node = create_node();
    printf("Enter positon to be inserted : ");
    scanf("%d",&pos);
    struct node* temp = *head;
    while (temp!=NULL && --pos) 
    {
        temp=temp->next;
    }
    node->next=temp->next;
    temp->next=node;
}

struct node* create_node()
{
    int data;
    scanf("%d",&data);
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void show_list(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d-->",head->data);
        head=head->next;
    }
}