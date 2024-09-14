#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};


void insert_at_head(struct node** head);
struct node* create_node();
void show_list(struct node* head);

int main()
{
    int n;
    struct node* head = NULL;
    printf("Enter the number of linked list : ");
    scanf("%d",&n);
    printf("Enter the elements into list : ");
    for(int i=0;i<n;i++)
        insert_at_head(&head);

    show_list(head);

    return 0;
}

void insert_at_head(struct node** head)
{
    struct node* new_node = create_node();
    if(*head==NULL)
    {
        *head = new_node;
        return;
    }
    new_node->next = (*head);
    (*head)->prev = new_node;
    *head = new_node;
    return;
}

struct node* create_node()
{
    int data;
    scanf("%d",&data);
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node; 
}

void show_list(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d-->",head->data);
        head = head->next;
    }
    printf("\n");
}