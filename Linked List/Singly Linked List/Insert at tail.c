#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_at_tail(struct node **head);
struct node* create_node();
void show_list(struct node *head);

int main()
{
    int n;
    struct node* head=NULL;
    printf("Enter the number of linked list : ");
    scanf("%d",&n);
    printf("Enter the elements into linked list : ");
    for(int i=0;i<n;i++)
        insert_at_tail(&head);

    show_list(head);
    return 0;
}

void insert_at_tail(struct node **head)
{
    struct node* node = create_node();
    if(*head==NULL)
    {
        *head = node;
        return;
    }
    struct node* temp = *head;
    while (temp->next!=NULL)
        temp = temp->next;

    temp->next = node;
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
void show_list(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d-->",head->data);
        head=head->next;
    }
}