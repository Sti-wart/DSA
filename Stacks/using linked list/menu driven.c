#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int size = 10;
int top = -1;

struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;

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

void push(int value)
{
    if(isFull())
    {
        printf("Stack is full. Cannot push items\n");
        return;
    }

    if(head==NULL)
    {
        head = create_node();
        head->data = value;
        top++;
        printf("%d pushed successfully\n",value);
        return;
    }

    struct node* temp = create_node();
    temp->data = value;
    temp->next = head;
    head = temp;
    top++;
    printf("%d pushed successfully\n",value);

    return;
}

void pop()
{
    if(isEmpty() || head==NULL)
    {
        printf("Stack is empty. Cannot pop item\n");
        return;
    }

    struct node* temp = head;
    head = head->next;
    top--;
    printf("%d popped succesfully\n",temp->data);
    free(temp);

    return;
}

void display()
{
    struct node* temp = head;
    printf("stack is -> ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{

    while(1)
    {
        printf("1.push      2.pop\n");
        printf("3.top       4.display\n");
        printf("5.isEmpty   6.isFull\n");
        printf("7.exit\n");
        printf("Enter the choice : ");

        int choice,data,item;
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: printf("Enter data to be pushed : ");
                    scanf("%d",&data);
                    push(data);
                    getch();
                    break;
            case 2: pop();
                    getch();
                    break;
            case 3: if(!isEmpty())
                        printf("top element = %d\n",head->data);
                    else
                        printf("no top element\n");
                    getch();
                    break;
            case 4: display();
                    getch();
                    break;
            case 5: if(isEmpty())
                        printf("Stack is empty\n");
                    else
                        printf("Stack is not empty\n");
                    getch();
                    break;
            case 6: if(isFull())
                        printf("Stack is full\n");
                    else
                        printf("Stack is not full\n");
                    getch();
                    break;
            case 7: exit(0);
                    
        }
    }  
    return 0;
}