#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack* s)
{
    if(s->top==-1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack* s)
{
    if(s->top==s->size-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack* s, int value)
{
    if(isFull(s))
    {
        printf("Stack is overflow. Cannot push element\n");
        return;
    }
    s->top++;
    s->arr[s->top] = value;
    printf("%d pushed successfully\n",value);
}

int main()
{
    struct stack* s;
    s = (struct stack*)malloc(sizeof(struct stack));

    printf("Enter the Max-size of the stack : ");
    scanf("%d",&s->size);
    s->top = -1;
    s->arr = (int*) malloc((s->size)*sizeof(int));

    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    
    return 0;
}