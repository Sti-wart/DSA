#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int s[10];
int size=10;
int top=-1;

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

void push(int value)
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

int pop()
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

void display()
{
    printf("All elements in stack : ");
    for(int i=0;i<=top;i++)
        printf("%d ",s[i]);
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
                        printf("top element = %d\n",s[top]);
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