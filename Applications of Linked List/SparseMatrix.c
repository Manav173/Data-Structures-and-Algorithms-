#include<stdio.h>
#include<stdlib.h>

struct node
{
    int r;
    int c;
    int v;
    struct node * next;
};

void createarray(int *arr,int r,int c)
{
    int n=0;
    printf("Enter the matrix : \n");
    for(int i=0;i<r*c;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Matrix is : \n");
    for(int i=0;i<r*c;i++)
    {
        printf("%d ",arr[i]);
        n++;
        if(n==c)
        {
            printf("\n");
            n=0;
        }
    }
}

void create(struct node **h,int *arr,int r,int c)
{
    struct node *cur,*p;
    int count=0,k=0;
    int a[r][c];    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            a[i][j]=arr[k];
            if(a[i][j]!=0)
                count++;
            k++;
        }   
    }
    *h=malloc(sizeof(struct node));
    (*h)->r=r;
    (*h)->c=c;
    (*h)->v=count;
    p=*h;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                cur=malloc(sizeof(struct node));
                cur->r=i;
                cur->c=j;
                cur->v=a[i][j];
                cur->next=NULL;
                p->next=cur;
                p=cur;
            }
        }
    } 
}

void join(struct node *h1,struct node *h2,struct node **h)
{
    struct node *p,*l,*cur;
    *h=NULL;

    if(h1->r==h2->r && h1->c==h2->c)
    {
        *h=malloc(sizeof(struct node));
        (*h)->r=h1->r;
        (*h)->c=h1->c;
        (*h)->v=h1->v+h2->v;
        l=(*h);
    }
    else
        return;

    for(p=h1->next;p!=NULL;p=p->next)
    {
        cur=malloc(sizeof(struct node));
        (*cur)=(*p);
        cur->next=NULL;
        l->next=cur;
        l=cur;
    }
    for(p=h2->next;p!=NULL;p=p->next)
    {
        cur=malloc(sizeof(struct node));
        (*cur)=(*p);
        cur->next=NULL;
        l->next=cur;
        l=cur;
    }
}

void simpl(struct node *h)
{
    struct node *p,*q,*prv;
    for(p=h->next;p!=NULL;p=p->next)
    {
        prv=p;
        q=p->next;
        while(q!=NULL)
        {
            if(q->r==p->r && q->c==p->c)
            {
                p->v += q->v;
                prv->next=q->next;
                free(q);
                q=prv->next;
                h->v--;
            }
            else
            {
                prv=q;
                q=q->next;
            }
        }
    }
}

void mul(struct node *h1,struct node *h2,struct node **h)
{
    if(h1->c != h2->r)
        return;
    
    (*h)=malloc(sizeof(struct node));
    (*h)->r=h1->r;
    (*h)->c=h2->c;
    (*h)->v=0;
    (*h)->next=NULL;

    struct node *p,*q,*cur,*k;
    k=(*h);
    for(p=h1->next;p!=NULL;p=p->next)
    {
        for(q=h2->next;q!=NULL;q=q->next)
        {
            if(p->c==q->r)
            {
                cur=malloc(sizeof(struct node));
                cur->c=q->c;
                cur->r=p->r;
                cur->v=q->v * p->v;
                cur->next=NULL;
                k->next=cur;
                k=k->next;
                (*h)->v++;
            }
        }
    }
}

void display(struct node *h)
{
    printf("\nThe sparse matrix is : \n");
    struct node *cur=h;
    while(cur!=NULL)
    {
        printf("%d %d %d\n",cur->r,cur->c,cur->v);
        cur=cur->next;
    }
}

int main()
{
    int r,c;
    printf("Enter the number of rows of matrix 1 : ");
    scanf("%d",&r);
    printf("Enter the number of columns of matrix 1 : ");
    scanf("%d",&c);
    int arr[r][c];
    createarray(&arr,r,c);
    struct node * h1=NULL;
    create(&h1,&arr,r,c);
    display(h1);
    printf("Enter the number of rows of matrix 2 : ");
    scanf("%d",&r);
    printf("Enter the number of columns of matrix 2 : ");
    scanf("%d",&c);
    arr[r][c];
    createarray(&arr,r,c);
    struct node * h2=NULL;
    create(&h2,&arr,r,c);
    display(h2);
    struct node * h3=NULL;
    printf("Addition of the two sparse matrix : \n");
    join(h1,h2,&h3);
    simpl(h3);
    display(h3); 
    printf("Multiplication of the two sparse matrix : \n");
    mul(h1,h2,&h3);
    simpl(h3);
    display(h3);
}