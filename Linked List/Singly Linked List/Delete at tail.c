#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_at_head(struct node**);
struct node* create_node();
void show_list(struct node*);
void delete_at_tail(struct node**);

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
    printf("\nThe node at tail is being deleted : ");
    delete_at_tail(&head);
    show_list(head);

    return 0;
}

void delete_at_tail(struct node** head)
{
    struct node* tail = *head;
    struct node* prev = NULL;
    while (tail->next!=NULL)
    {
        prev=tail;
        tail=tail->next;
    }
    prev->next=NULL;
    free(tail);
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