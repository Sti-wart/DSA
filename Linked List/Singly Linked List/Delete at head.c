#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_at_head(struct node**);
struct node* create_node();
void show_list(struct node*);
void delete_at_head(struct node**);

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
    printf("\nThe node at head is being deleted : ");
    delete_at_head(&head);
    show_list(head);

    return 0;
}

void delete_at_head(struct node** head)
{
    struct node* temp = *head;
    *head = (*head)->next;
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