#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

void insert_at_tail(struct node** head, int data);
void delete_at_head(struct node** head);
void show_list(struct node* head);

int main()
{
    int n;
    struct node* head=NULL;
    printf("Enter the number of linked list : ");
    scanf("%d",&n);
    printf("Enter the elements into the list : ");
    for(int i=0;i<n;i++)
    {
        int data;
        scanf("%d",&data);
        insert_at_tail(&head,data);
    }
    show_list(head);
    delete_at_head(&head);
    show_list(head);

    return 0;
}

void insert_at_tail(struct node** head, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
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

void delete_at_head(struct node** head)
{
    if(*head==NULL)
        return;

    struct node* temp = *head;
    (*head) = (*head)->next; 
    free(temp);
    (*head)->prev = NULL;
    return;
}

void show_list(struct node* head)
{
    while (head!=NULL)
    {
        printf("%d-->",head->data);
        head = head->next;
    }
    printf("\n");
    return;
}