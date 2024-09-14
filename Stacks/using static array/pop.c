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
    top=top+1;
    s[top]=value;
    printf("%d pushed successfully\n",value);
}

int pop(int *s)
{
    if(isEmpty())
    {
        printf("Stack is empty, cannot pop element\n");
        return -1;
    }
    printf("%d poped succesfully\n",s[top]);
    int item = top;
    top = top-1;
    return s[item];
}

int main()
{
    size = 5;
    int s[size];
    top = -1;

    push(s,10);
    push(s,20);

    pop(s);
    pop(s);
    pop(s);    
    return 0;
}