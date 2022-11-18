#include<stdio.h>
#include<stdlib.h>
#define MAX 6

typedef struct
{
    int data[MAX];
    int top;
}stack;

void init(stack *s)
{
    s->top=-1;
}

int push(stack *s, int v)
{
    if(s->top == MAX-1)
    {
        printf("Overflow !!!\n");
        return 1;
    }
    else
    {
        s->top++;
        s->data[s->top] = v;
        return 0;
    }
}

int pop(stack *s,int *v)
{
    if(s->top == -1)
    {
        printf("Underflow !!!\n");
        return 1;
    }
    *v=s->data[s->top];
    s->top--;
    return 0;
}

void display(stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    
    for(int i=s->top;i>=0;i--)
        printf("%d ",s->data[i]);
    
    printf("\n");
}

int main()
{
    stack s;
    init(&s);
    int v,choice;

    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    printf("4.Exit\n");

    while(choice != 4)
    {
        printf("Enter the options : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the value to be inserted : ");
                    scanf("%d",&v);
                    int t=push(&s,v);
                    break;

            case 2: t=pop(&s,&v);
                    if(t==1)
                        break;
                    printf("The value poped is %d \n",v);
                    break;

            case 3: printf("The stack is : ");
                    display(&s);
                    break;

            case 4: printf("Exit !\n");
                    break;

            default: printf("Wrong option !\n");
        }
    }
    return 0;
}
