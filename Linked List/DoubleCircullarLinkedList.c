#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *next;
    int data;
    struct node *prv;
};

void create(struct node **h,int n)
{
    struct node *cur;
    printf("Enter the data in the node : ");
    for(int i=0;i<n;i++)
    {
        cur=malloc(sizeof(struct node));
        scanf("%d",&cur->data);
        cur->prv=cur->next=NULL;
        if(*h==NULL)
        {
            *h=cur;
            cur->next=cur->prv=cur;
        }
        else
        {
            cur->prv=(*h)->prv;
            cur->next=(*h);
            (*h)->prv->next=cur;
            (*h)->prv=cur;
        }
    }
}

void insert(struct node **h,int pos,int v)
{
    struct node *cur,*p;
    cur=malloc(sizeof(struct node));
    cur->next=cur->prv=NULL;
    cur->data=v;

    if(*h==NULL)
    {
        *h=cur;
        cur->next=cur->prv=cur;
    }
    else if(pos==0)
    {
        cur->prv=(*h)->prv;
        cur->next=(*h);
        (*h)->prv->next=cur;
        (*h)->prv=cur;
        (*h)=cur;
    }
    else
    {
        int i=1;
        p=*h;
        while(i<pos && p->next!=NULL)
        {
            p=p->next;
            i++;
        }
        if(p->next==NULL)
        {
            cur->prv=p;
            p->next=cur;
        }
        else
        {
            cur->prv=p;
            cur->next=p->next;
            cur->next->prv=cur;
            cur->prv->next=cur;
        }
    }
}

void delete(struct node **h,int v)
{
    struct node *p;
    if(*h==NULL)
        printf("Linked list node is empty\n");
    
    for(p=*h;p!=NULL;p=p->next)
    {
        if(p->data==v)
            break;
    }
        
    if(p==NULL)
        printf("Element not found\n");

    else
    {
        if(p==*h && p->next==NULL)
        {
            free(p);
            *h=NULL;
        }
        else if(p==*h)
        {
            *h=p->next;
            p->prv->next=p->next;
            p->next->prv=p->prv;
            free(p);
        }
        else if(p->next==NULL)
        {
            p->prv->next=p->next;
            p->next->prv=p->prv;
            free(p);
        }
        else
        {
            p->prv->next=p->next;
            p->next->prv=p->prv;
            free(p);
        }
    }
}

void deletemul(struct node **h,int v)
{
    struct node *p,*q;
    if(*h==NULL)
        printf("Linked list node is empty\n");
    
    for(p=*h;p!=NULL;)
    {
        if(p->data==v)
        {
            if(p==*h && p->next==NULL)
            {
                free(p);
                *h=NULL;
                p=NULL;
            }
            else if(p==*h)
            {
                *h=p->next;
                p->prv->next=p->next;
                p->next->prv=p->prv;
                free(p);
                p=*h;
            }
            else if(p->next==NULL)
            {
                p->prv->next=NULL;
                p->next->prv=p->prv;
                free(p);
                p=NULL;
            }
            else
            {
                q=p->next;
                p->prv->next=p->next;
                p->next->prv=p->prv;
                free(p);
                p=q;
            }
            if(*h!=NULL)
                (*h)->prv=NULL;
        }
        else
            p=p->next;
    }
}

void search(struct node *h,int v,int *count)
{
    struct node *p=h;

    while(p!=NULL)
    {
        if(p->data==v)
        {
            printf("%d is present at %d node\n",p->data,count);
            return;
        }
        else
        {
            p=p->next;
            count++;
        }
    }
    printf("Not Found !\n");
}

void display(struct node *h)
{
    struct node *p=h;

    while(p->next!=h)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d ",p->data);
    printf("\n");
}

int main()
{
    struct node *head=NULL;
    int v,p,n,choice=0,count=0;
    printf("Enter the number of nodes in double linked list : ");
    scanf("%d",&n);
    create(&head,n);

    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Delete multiple elements\n");
    printf("4.Display\n");
    printf("5.Find\n");
    printf("6.Exit\n");

    do
    {
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : printf("Enter the value to be inserted : ");
                     scanf("%d",&v);
                     printf("Enter the position at which the value is to be inserted : ");
                     scanf("%d",&p);
                     insert(&head,p,v);
                     break;
                    
            case 2 : printf("Enter the value to be deleted : ");
                     scanf("%d",&v);
                     delete(&head,v);
                     break;

            case 3 : printf("Enter the value to be deleted : ");
                     scanf("%d",&v);
                     deletemul(&head,v);
                     break;

            case 4 : printf("Double linked list : ");
                     display(head);
                     break;
                    
            case 5 : printf("Enter the value to be found : ");
                     scanf("%d",&v);
                     search(head,v,&count);
                     if(count!=0)
                        printf("The value is at %d node\n",count);
                     break;

            case 6 : printf("Exiting !\n");
                     break;

            default : printf("Enter a correct option !\n"); 
        }
    }while(choice!=6);

    return 0;
}