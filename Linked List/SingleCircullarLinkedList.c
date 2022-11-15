#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create(struct node **h,int n)
{
    struct node *cur,*p;

    for(int i=0;i<n;i++)
    {
        cur=malloc(sizeof(struct node));
        scanf("%d",&cur->data);
        cur->next=NULL;

        if(*h==NULL)
            *h=p=cur->next=cur;

        else
        {
            cur->next=p->next;
            p->next=cur;
            p=cur;
        }
    }
}

void insert(struct node **h,int pos,int v)
{
    struct node *cur,*p;
    cur=malloc(sizeof(struct node));
    cur->data=v;
    cur->next=NULL;

    if(*h==NULL)
        *h=cur->next=cur;

    else if(pos==0)
    {
        for(p=*h;p->next!=*h;p=p->next);
        cur->next=*h;
        p->next=cur;
        *h=cur;
    }

    else
    {
        int i;
        for(i=1,p=*h;i<pos;p=p->next,i++);
        cur->next=p->next;
        p->next=cur;
    }
}

void delete(struct node **h,int pos,int *v)
{
    struct node *prv,*p;

    if(*h==NULL)
        printf("List is empty\n");

    else
    {
        int i;
        for(i=0,p=*h;i<pos;i++)
        {
            prv=p;
            p=p->next;
        }

        *v=p->data;

        if(p==*h && p==p->next)
        {
            *h=NULL;
            free(p);
        }
        else
        {
            if(prv==NULL)
                for(prv=*h;p->next!=*h;p=p->next);
            
            if(p==*h)
                *h=p->next;

            prv->next=p->next;
            free(p);
        }
    }
}

void display(struct node *h)
{
    if(h==NULL)
        printf("Linked list is empty\n");
    
    struct node *cur=h;

    while(cur->next!=h)
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    printf("%d\n",cur->data);
}

int main()
{
    struct node *head=NULL;
    int n,v,pos,choice=0;

    printf("Enter the number of nodes you want to create : ");
    scanf("%d",&n);
    printf("Enter the values in the single linked list : ");
    create(&head,n);

     printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Display\n");
    printf("4.Exit\n");

    do
    {
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : printf("Enter the value to be inserted : ");
                     scanf("%d",&v);
                     printf("Enter the position at which the value is to be inserted : ");
                     scanf("%d",&pos);
                     insert(&head,pos,v);
                     break;

            case 2 : printf("Enter the position at which the value is to be delted : ");
                     scanf("%d",&pos);
                     delete(&head,pos,&v);
                     break;

            case 3 : printf("Single Linked List : ");
                     display(head);
                     break;

            case 4 : printf("Exiting !\n");
                     break;

            default : printf("Enter a correct option !\n");
        }
    }while(choice!=4);

    return 0;
}