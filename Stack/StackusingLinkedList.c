#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct
{
    struct node *top;
}stack;

int push(stack *s,int v)
{
    struct node *cur;
    cur=malloc(sizeof(struct node));
    if(cur==NULL)
    {
        printf("Overflow !\n");
        return 1;
    }
    cur->data=v;
    cur->next=NULL;
    cur->next=s->top;
    s->top=cur;
    return 0;
}

int pop(stack *s,int *v)
{
    if(s->top==NULL)
        printf("Underflow !\n");
    
    *v=s->top->data;
    s->top=s->top->next;
    return 0;
}

void display(stack s)
{
    stack *cur;
    cur=&s;
    if(cur->top==NULL)
        printf("Stack is empty !\n");

    while(cur->top!=NULL)
    {
        printf("%d ",cur->top->data);
        cur->top=cur->top->next;
    }
    printf("\n");
}

int main()
{
    stack s;
    s.top = NULL;
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
                    printf("The value poped is %d \n",v);
                    break;

            case 3: printf("The stack is : ");
                    display(s);
                    break;

            case 4: printf("Exit !\n");
                    break;

            default: printf("Wrong option !\n");
        }
    }
    return 0;
}