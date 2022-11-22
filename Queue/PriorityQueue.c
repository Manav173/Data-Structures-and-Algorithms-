#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct
{
    struct dp{
        int d,p;
    }data[MAX];
    int f;
    int r;
}queue;

int insert(queue *q,struct dp d)
{
    if(q->r==MAX-1)
    {
        printf("Queue is full\n");
        return 1;
    }

    if(q->r==-1)
        q->r=q->f=0;

    else
        q->r++;
    
    q->data[q->r]=d;
    return 0;
}

int delete(queue *q,struct dp *p)
{
    if(q->f==-1)
    {
        printf("Queue is empty\n");
        return 1;
    }

    if(q->r==q->f)
    {
        *p=q->data[q->f];
        q->f=q->r=-1;
    }

    else
    {
        int min=q->f;
        for(int i=q->f+1;i<=q->r;i++)
        {
            if(q->data[i].p<q->data[min].p)
                min=i;
        }
        *p=q->data[min];
        for(int i=min+1;i<=q->r;i++)
            q->data[i-1]=q->data[i];
        q->r--;
    }
    return 0;
}

void display(queue *q)
{
    if(q->f==-1)
    {
        printf("Queue is empty\n");
        return;
    }

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
    struct dp k;
    q.f=q.r=-1;
    int choice=0,t;

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
                    scanf("%d",&k.d);
                    printf("Enter the priority of the value : ");
                    scanf("%d",&k.p);
                    t=insert(&q,k);
                    break;

            case 2: t=delete(&q,&k);
                    if(t==0)
                        printf("The value poped is %d \n",k.d);
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