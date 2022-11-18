#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct
{
    int data[MAX];
    int f,r;
}queue;

void init(queue *q)
{
    q->f=q->r=-1;
}

int insert(queue *q,int v,int type)
{
    if(q->f==((q->r+1)%MAX))
    {
        printf("Queue is full\n");
        return 1;
    }

    if(q->f==-1)
    {
        q->r=q->f=0;
        q->data[q->r]=v;
        return 0;
    }

    else if(type==1)
    {
        q->r=(q->r+1)%MAX;
        q->data[q->r]=v;
        return 0;
    }

    else
    {
        q->f=(q->f+MAX-1)%MAX;
        q->data[q->f]=v;
    }
    return 0;
}

int delete(queue *q,int *v,int type)
{
    if(q->f==-1)
    {
        printf("Queue is empty\n");
        return 1;
    }
    
    if(q->f==q->r)
    {
        *v=q->data[q->f];
        q->r=q->f=-1;
        return 0;
    }

    else if(type==0)
    {
        *v=q->data[q->f];
        q->f=(q->f+1)%MAX;
        return 0;
    }

    else
    {
        *v=q->data[q->r];
        q->r=(q->r+MAX-1)%MAX;
    }
    return 0;
}

void display(queue *q)
{
    if(q->f==-1)
        printf("Queue is empty\n");

    int i=q->f;
    do
    {
        printf("%d ",q->data[i]);
        i=(i+1)%MAX;
    }while(i!=(q->r+1));
    printf("\n");
}

int main()
{
    queue q;
    init(&q);

    int v,choice=0,type;

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
            case 1: printf("Enter the type (0 for front insertion and 1 for rear insertion) : ");
                    scanf("%d",&type);
                    printf("Enter the value to be inserted : ");
                    scanf("%d",&v);
                    int t=insert(&q,v,type);
                    break;

            case 2: printf("Enter the type (0 for front deletion and 1 for rear deletion) : ");
                    scanf("%d",&type);
                    t=delete(&q,&v,type);
                    if(t==1)
                        break;
                    printf("The value poped is %d \n",v);
                    break;

            case 3: printf("The queue is : ");
                    display(&q);
                    break;

            case 4: printf("Exit !\n");
                    break;

            default: printf("Wrong option !\n");
        }
    }while(choice != 4);
    return 0;
}