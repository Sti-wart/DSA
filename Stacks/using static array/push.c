#include<stdio.h>

int size;
int top;

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

void push(int *s, int value)
{
    if(isFull())
    {
        printf("Stack is overflow. Cannot push element\n");
        return;
    }
    s[top]=value;
    printf("pushed successfully\n");
    top++;
}

int main()
{
    printf("Enter Max-size of stack : ");
    scanf("%d",&size);

    int s[size];
    top = -1;
    int no_of_elements = 0;
    
    while(no_of_elements<=size)
    {
        int data;
        printf("Push elements : ");
        scanf("%d",&data);
        printf("%d is in process to push...",data);
        push(s,data);
        no_of_elements++;
    }    
    return 0;
}