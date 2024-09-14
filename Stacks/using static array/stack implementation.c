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

int main()
{
    printf("Enter Max-size of stack : ");
    scanf("%d",&size);

    int s[size];
    top = -1;

    if(isEmpty())
        printf("Stack is empty now\n");
    else
        printf("Stack is not empty\n");

    if(isFull())
        printf("Stack is full\n");
    else
        printf("Stack is not full\n");    

}