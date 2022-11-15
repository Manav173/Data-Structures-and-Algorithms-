#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef;
    int exp;
    struct node * next;
};

void create(struct node **h)
{
    int n;
    printf("Enter the no. of terms : ");
    scanf("%d",&n);

    struct node *l;
    for(int i=0;i<n;i++)
    {
        struct node *cur= malloc(sizeof(struct node));
        cur->next=NULL;
        printf("Enter the coefficient and exponent : ");
        scanf("%d %d",&cur->coef,&cur->exp);
        if(*h==NULL)
            *h=l=cur;

        else
        {
            l->next=cur;
            l=cur;
        }
    }
}

void createres(struct node **h,int coef,int exp)
{
    struct node *l;
    struct node *cur= malloc(sizeof(struct node));
    cur->next=NULL;
    cur->coef=coef;
    cur->exp=exp;
    if(*h==NULL)
        *h=l=cur;
    else
    {
        l->next=cur;
        l=cur;
    }
}

struct node * add(struct node *h1,struct node *h2)
{
    struct node *res=NULL;
    struct node *p=h1,*q=h2;
    while(p!=NULL && q!=NULL)
    {
        if(p->exp==q->exp)
        {
            createres(&res,p->coef+q->coef,p->exp);
            p=p->next;
            q=q->next;
        }
        else if(p->exp<q->exp)
        {
            createres(&res,p->coef,p->exp);
            p=p->next;
        }
        else
        {
            createres(&res,q->coef,q->exp);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        createres(&res,p->coef,p->exp);
        p=p->next;
    }
    while(q!=NULL)
    {
        createres(&res,q->coef,q->exp);
        q=q->next;
    }
    return res;
}

struct node * mul(struct node *h1,struct node *h2)
{
    struct node *i,*j,*res;

    for(i=h1;i!=NULL;i=i->next)
    {
        for(j=h2;j!=NULL;j=j->next)
        {
            createres(&res,i->coef*j->coef,i->exp+j->exp);
        }
    }
    return res;
}

void display(struct node *h)
{
    struct node *cur=h;
    while(cur->next!=NULL)
    {
        printf("%d x^%d + ",cur->coef,cur->exp);
        cur=cur->next;
    }
    printf("%d x^%d\n",cur->coef,cur->exp);
}

void simpl(struct node *h)
{
    struct node *p=h,*q,*prv;
    while(p->next!=NULL)
    {
        prv=p;
        q=p->next;
        while(q!=NULL)
        {
            if(p->exp!=q->exp)
            {
                prv=q;
                q=q->next;
            }
            else
            {
                p->coef = p->coef + q->coef;
                prv->next=q->next;
                free(q);
                q=prv->next;
            }
        }
        p=p->next;
    }
}

void sort(struct node **h)
{
    int count =0;
    struct node *p=*h;
    int temp;
    do
    {
        count=0;
        p=*h;
        while(p->next!=NULL)
        {
            if(p->next->exp>p->exp)
            {
                temp=p->next->exp;
                p->next->exp=p->exp;
                p->exp=temp;
                temp=p->next->coef;
                p->next->coef=p->coef;
                p->coef=temp;
                count=1;
            }
            p=p->next;
        }
    }while(count);
}

int main()
{
    struct node *head1=NULL,*head2=NULL,*head=NULL;
    create(&head1);
    create(&head2);
    printf("Polynomial 1 : ");
    display(head1);
    printf("Polynomial 2 : ");
    display(head2);
    head = add(head1,head2);
    simpl(head);
    sort(&head);
    printf("Polynomial after addition is : ");
    display(head);
    head = mul(head1,head2);
    simpl(head);
    sort(&head);
    printf("Polynomial after multiplication is : ");
    display(head);
    return 0;
}
