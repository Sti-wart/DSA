#include<stdio.h>
#include<stdlib.h>

int size = 10;
int top = -1;

struct node{
    int data;
    struct node* next;
};

int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if(top==size-1)
    {
        return 1;
    }
    return 0;
}

struct node* create_node()
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next = NULL;
    return new_node;
}

void push(struct node** head, int value)
{
    if(isFull())
    {
        printf("Stack is full. Cannot push items\n");
        return;
    }

    if(*head==NULL)
    {
        *head = create_node();
        (*head)->data = value;
        top++;
        printf("%d is pushed successfully\n",value);
        return;
    }

    struct node* temp = create_node();
    temp->data = value;
    temp->next = *head;
    *head = temp;
    top++;
    printf("%d is pushed successfully\n",value);

    return;
}

int main()
{
    struct node* s = NULL;

    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    
    return 0;
}