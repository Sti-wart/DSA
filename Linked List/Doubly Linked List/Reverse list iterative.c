#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

void reverse_list(struct node** head);
void insert_at_tail(struct node** head);
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
        insert_at_tail(&head);

    show_list(head);
    reverse_list(&head);
    show_list(head);
    
    return 0;
}

void reverse_list(struct node** head)
{
    if(*head==NULL)
        return;

    while((*head)->next!=NULL)
    {
        struct node* temp = (*head)->next;
        (*head)->next = (*head)->prev;
        (*head)->prev = temp;
        (*head) = temp;
    }
    (*head)->next = (*head)->prev;
    (*head)->next->prev = (*head);
    return;
}

void insert_at_tail(struct node** head)
{
    struct node* new_node = create_node();
    if(*head==NULL)
    {
        *head = new_node;
        return;
    }
    struct node* temp = *head;
    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;
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