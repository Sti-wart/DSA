#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int search(struct node* head, int key);
void insert_at_head(struct node **head);
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
    printf("Enter the key to be searched : ");
    int key;
    scanf("%d",&key);
    if(search(head,key))
        printf("%d is found in the list");
    else
        printf("%d is not found in the list");
    
    return 0;
}

int search(struct node* head, int key)
{
    if(head==NULL)
        return 0;
    
    if(head->data==key)
        return 1;
    return search(head->next,key);
}

void insert_at_head(struct node** head)
{
    struct node* new_node = create_node();
    new_node->next = *head;
    *head = new_node;
    return;
}

struct node* create_node()
{
    int data;
    scanf("%d",&data);
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

void show_list(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d-->",head->data);
        head =head->next;
    }
    printf("\n");
}