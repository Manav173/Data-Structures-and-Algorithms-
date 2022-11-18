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
    if(q->r==MAX-1)
    {
        printf("Queue is full\n");
        return 1;
    }

    if(q->r==-1)
    {
        q->r=q->f=0;
        q->data[q->r]=v;
        return 0;
    }

    else if(type==1)
    {
        q->r++;
        q->data[q->r]=v;
        return 0;
    }

    else
    {
        for(int i=q->r;i>=q->f;i--)
            q->data[i+1]=q->data[i];
        q->data[q->f]=v;
        q->r++;
    }
}

int delete(queue *q,int *v)
{
    if(q->f==-1)
    {
        printf("Queue is empty\n");
        return 1;
    }
    *v=q->data[q->f];
    if(q->f==0 && q->r==0)
    {
        q->r=q->f=-1;
        return 0;
    }
    else
    {
        for(int i=q->f+1;i<=q->r;i++)
            q->data[i-1]=q->data[i];
        q->r--;
        return 0;
    }
}

void display(queue *q)
{
    if(q->f==-1)
        printf("Queue is empty\n");

    for(int i=q->f;i<=q->r;i++)
        printf("%d ",q->data[i]);
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

            case 2: t=delete(&q,&v);
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