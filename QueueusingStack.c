#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct
{
    int data[MAX];
    int top;
}stack;

stack s[2];

void push(stack *s, int v)
{
    if(s->top == MAX-1)
        printf("Overflow !!!\n");
    
    else
    {
        s->top++;
        s->data[s->top] = v;
    }
}

void pop(stack *s,int *v)
{
    if(s->top == -1)
    {
        printf("Underflow !!!\n");
        *v=19780;
    }
    *v=s->data[s->top];
    s->top--;
}

void insert(int v)
{
    push(&s[0],v);
}

void delete(int *v)
{
    int t,a;
    if(s[0].top==-1 && s[1].top==-1)
        return;
    
    if(s[1].top!=-1)
        pop(&s[1],&a);

    else
    {
        while(s[0].top!=-1)
        {
            pop(&s[0],&t);
            push(&s[1],t);
        }
        pop(&s[1],&a);
    }
    *v=a;
}

void display()
{
    if(s[0].top == -1 && s[1].top == -1)
    {
        printf("\n");
        return;
    } 

    for(int i=s[1].top;i>=0;i--)
        printf("%d ",s[1].data[i]);
    
    for(int i=0;i<=s[0].top;i++)
        printf("%d ",s[0].data[i]);
    
    printf("\n");
}

int main()
{
    for (int i=0;i<2;i++)
        s[i].top=-1;

    int v,choice=0;

    printf("1.Insert\n");
    printf("2.Remove\n");
    printf("3.Display\n");
    printf("4.Exit\n");

    do
    {
        printf("Enter the options : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the value to be inserted : ");
                    scanf("%d",&v);
                    insert(v);
                    break;

            case 2: delete(&v);
                    if(v!=19780)
                        printf("The value poped is %d \n",v);
                    break;

            case 3: printf("The queue is : ");
                    display();
                    break;

            case 4: printf("Exit !\n");
                    break;

            default: printf("Wrong option !\n");
        }
    }while(choice != 4);
    return 0;
}
