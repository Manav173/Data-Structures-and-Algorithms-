#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}queue;

void enqueue(queue **front, queue **rear, int value)
{
    queue *cur;
    cur=malloc(sizeof(queue));
    if(cur==NULL)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        cur->data=value;
        cur->next=NULL;
        if(*front==NULL)
            (*front)=(*rear)=cur;
        else
        {
            (*rear)->next=cur;
            (*rear)=cur;
        }
    }
}

int dequeue(queue **front)
{
    int t;
    queue *ptr=*front;
    if(ptr==NULL)
    {
        printf("Queue is empty\n");
        t=123490;
    }
    else
    {
        t=ptr->data;
        (*front)=ptr->next;
        free(ptr);
    }
    return t;
}

void peek(queue *front)
{
    if(front==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        while(front!=NULL)
        {
            printf("%d ",front->data);
            front=front->next;
        }
        printf("\n");
    }
}

int main()
{
    queue *front=NULL,*rear=NULL;
    int v,choice =0;
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Peek\n");
    printf("4.Exit\n");

    do
    {
        printf("\nEnter the choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the value to be inserted : ");
                    scanf("%d",&v);
                    enqueue(&front,&rear,v);
                    break;
            
            case 2: v=dequeue(&front);
                    if(v!=123490)
                    printf("The value deleted is : %d\n",v);
                    break;

            case 3: peek(front);
                    break;
                
            case 4: printf("Exiting !\n");
                    break;
            
            default: printf("Enter correct choice!\n");
        }
    }while(choice != 4);
    return 0;
}