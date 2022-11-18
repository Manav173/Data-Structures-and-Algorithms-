#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct
{
    int data[MAX];
    int f,r;
}queue;

queue q[2];
int cur=0;

void insert(queue *q,int v)
{
    if(q->r==MAX-1)
        printf("Queue is full\n");

    if(q->r==-1)
    {
        q->r=q->f=0;
        q->data[q->r]=v;
    }
    else
    {
        q->r++;
        q->data[q->r]=v;
    }
}

void delete(queue *q,int *v)
{
    if(q->f==-1)
    {
        printf("\n");
        *v=19780;
        return;
    }
    
    *v=q->data[q->f];
    if(q->f==0 && q->r==0)
        q->r=q->f=-1;

    else
    {
        for(int i=q->f+1;i<=q->r;i++)
            q->data[i-1]=q->data[i];
        q->r--;
    }
}

void display(queue *q)
{
    if(q->f==-1)
        return;

    for(int i=q->f;i<=q->r;i++)
        printf("%d ",q->data[i]);
    printf("\n");   
}

void push(int v)
{
    insert(&q[cur],v);
}

void pop(int *v)
{
    int t;
    if(q[cur].r != -1)
    {
        while(1)
        {
            delete(&q[cur],&t);
            if(q[cur].f==-1)
            {
                *v=t;
                cur=(cur+1)%2;
                return;
            }
            insert(&q[(cur+1)%2],t);
        }
    }
}

int main()
{
    for(int i=0;i<2;i++)
        q[i].f=q[i].r=-1;
    
    int v,choice=0;

    printf("1.Push\n");
    printf("2.Pop\n");
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
                    push(v);
                    break;

            case 2: pop(&v);
                    if(v!=19780)
                        printf("The value poped is %d \n",v);
                    break;

            case 3: printf("The stack is : ");
                    display(&q[cur]);
                    break;

            case 4: printf("Exit !\n");
                    break;

            default: printf("Wrong option !\n");
        }
    }while(choice != 4);
    return 0;
}
