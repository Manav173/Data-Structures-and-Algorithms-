#include<stdio.h>
#include<stdlib.h>

# define max 5

typedef struct
{
    int data[max];
    int size;
}arraylist;

void init(arraylist *a)
{
    a->size = 0;
}

void insert(arraylist *a, int p, int v)
{
    if(a->size == max)
        printf("Array list is full\n");

    int i;
    for(i=a->size-1;i>=p;i--)
        a->data[i+1]=a->data[i];
    a->data[i+1]=v;
    a->size++;
}

void delete(arraylist *a,int p,int *v)
{
    if(a->size==0)
        printf("Array list is empty\n");
    
    else if(p>a->size)
        printf("Can not be deleted\n");
    
    *v=a->data[p];
    for(int i=p;i<a->size;i++)
        a->data[i]=a->data[i+1];
    a->size--;
}

void display(arraylist a)
{
    for(int i=0;i<a.size;i++)
        printf("%d ",a.data[i]);
    printf("\n");
}

void find(arraylist a,int *p,int v)
{
    for(int i=0;i<a.size;i++)
    {
        if(a.data[i]==v)
            *p=i;
    }
}

int main()
{
    arraylist a;
    int v,p,choice=0;
    init(&a);

    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Display\n");
    printf("4.Find\n");
    printf("5.Exit\n");

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
                     insert(&a,p,v);
                     break;
                    
            case 2 : printf("Enter the position at which the value is to be deleted : ");
                     scanf("%d",&p);
                     delete(&a,p,&v);
                     printf("Deleted value : %d \n",v);
                     break;

            case 3 : printf("Array list : ");
                     display(a);
                     break;
                    
            case 4 : printf("Enter the value to be found : ");
                     scanf("%d",&v);
                     find(a,&p,v);
                     printf("The value is at position : %d \n",p);
                     break;

            case 5 : printf("Exiting !\n");
                     break;

            default : printf("Enter a correct option !\n"); 
        }
    }while(choice!=5);

    return 0;
}
