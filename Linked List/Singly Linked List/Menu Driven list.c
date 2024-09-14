#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* head = NULL;

void insert_at_head(int data);
void insert_at_tail(int data);
void insert_at_mid(int data, int pos);
struct node* create_node();
void delete_at_head();
void delete_at_tail();
void delete_at_mid(int pos);
void show_list();
int length();
void search(int data);


int main()
{
    int end = 0;
    while(!end)
    {
        printf("\n");
        printf("1. Insert head       2. Insert tail\n");
        printf("3. Insert at mid     4. Delete head\n");
        printf("5. Delete tail       6. Delete at mid\n");
        printf("7. Length of List    8. Print List\n");
        printf("9. search element    10. exit the program\n");
        printf("\nEnter the choice you want to perform : ");
        
        int choice,data,pos;
        scanf("%d",&choice);

        switch (choice)
        {
            case 1 :    printf("\nEnter the data : ");
                        scanf("%d",&data);
                        insert_at_head(data);
                        break;
            case 2 :    printf("\nEnter the data : ");
                        scanf("%d",&data);
                        insert_at_tail(data);
                        break;
            case 3 :    show_list();
                        printf("\nEnter the data : ");
                        scanf("%d",&data);
                        printf("Enter the position to be inserted : ");
                        scanf("%d",&pos);
                        insert_at_mid(data,pos);
                        break;
            case 4 :    delete_at_head();
                        break;
            case 5 :    delete_at_tail();
                        break;
            case 6 :    show_list();
                        printf("\nEnter the position to be deleted : ");
                        scanf("%d",&pos);
                        delete_at_mid(pos);
                        getch();
                        break;
            case 7 :    printf("The length of the list : %d\n",length());
                        getch();
                        break;
            case 8 :    show_list();
                        getch();
                        break;
            case 9 :    show_list();
                        printf("\nEnter the element to be searched : ");
                        scanf("%d",&data);
                        search(data);
                        getch();
                        break;
            case 10:    end = 1;
                        printf("\nThank You\n");
                        break;
        
            default:    printf("Wrong choice! Enter valid choice ");
        }
    }
}

void insert_at_head(int data)
{
    struct node* new_node = create_node();
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_tail(int data)
{
    struct node* new_node = create_node();
    new_node->data = data;

    if(head==NULL)
    {
        head = new_node;
        return;
    }

    struct node* temp = head;
    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = new_node;
}

void insert_at_mid(int data, int pos)
{
    if(head==NULL)
    {
        printf("The list is Empty! can't insert to middle\n");
        printf("Try insert_at_head()\n");
        return;
    }
    if(pos==0)
    {
        printf("You must call insert_at_head() for 0th position\n");
        return;
    }
    if(pos==length())
    {
        printf("You must call insert_at_tail() for last position\n");
        return;
    }
    if(pos>length())
    {
        printf("Invalid position\n");
        return;
    }

    struct node* new_node = create_node();
    new_node->data = data;

    struct node* temp = head;
    int count=1;
    while(count<pos)
    {
        temp = temp->next;
        count++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

struct node* create_node()
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->next = NULL;
    return node;
}

void delete_at_head()
{
    if(head==NULL)
    {
        printf("The list is Empty! Plz insert element first\n");
        return;
    }
    
    struct node* temp = head;
    head = head->next;
    free(temp);
}

void delete_at_tail()
{
    if(head==NULL)
    {
        printf("The list is Empty! Plz insert element first\n");
        return;
    }

    struct node* prev = NULL;
    struct node* temp = head;
    while(temp->next!=NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void delete_at_mid(int pos)
{
    if(head==NULL)
    {
        printf("The list is Empty! Plz insert element first\n");
        return;
    }
    if(pos==0)
    {
        printf("You must call delete_at_head() for 0th position\n");
        return;
    }
    if(pos-1==length())
    {
        printf("You must call delete_at_tail() for last position\n");
        return;
    }

    int count=1;
    struct node* prev = NULL;
    struct node* temp = head;

    while(count<=pos)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }
    prev->next = temp->next;
    free(temp);
}

void show_list()
{
    if(head==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    
    struct node* temp = head;
    printf("The list is : ");
    while(temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int length()
{
    if(head==NULL)
    {
        printf("The list is empty\n");
        return 0;
    }

    struct node* temp = head;
    int len = 0;
    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void search(int data)
{
    if(head==NULL)
    {
        printf("The list is Empty! NO Elements found\n");
        return;
    }
    struct node* temp = head;
    int index=-1;
    while (temp!=NULL) 
    {
        index++;
        if(temp->data==data)
        {
            printf("The element %d is found in the list at %d index\n",data,index);
            return;
        }
        temp = temp->next;
    }
    printf("The element %d is not found in the list\n",data);
}