#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a>b)?a:b)

struct node
{
    int data;
    struct node *l,*r;
};

struct node * insert(struct node *root,int v)
{
    if(root==NULL) 
    {
        struct node *cur=malloc(sizeof(struct node));
        cur->data=v;
        cur->l=cur->r=NULL;
        return cur;
    }
    if(v>root->data)
    {
        root->r=insert(root->r,v);
        return root;
    }
    if(v<root->data)
    {
        root->l=insert(root->l,v);
        return root;
    }
}

void preorder(struct node * root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->l);
        preorder(root->r);
    }
}

void inorder(struct node * root)
{
    if(root != NULL)
    {
        inorder(root->l);
        printf("%d ",root->data);
        inorder(root->r);
    }
}
void postorder(struct node * root)
{
    if(root != NULL)
    {
        postorder(root->l);
        postorder(root->r);
        printf("%d ",root->data);
    }
}

struct node * getmax(struct node * root)
{
    if(root==NULL)
        return NULL;
    
    if(root->r==NULL)
        return root;

    else
        return getmax(root->r);
}

struct node * findmin(struct node * root)
{
    if(root==NULL)
        return NULL;
    
    if(root->l==NULL)
        return root;

    else
        return findmin(root->l);
}

int height(struct node * root)
{
    int h1,h2,h;
    if(root==NULL)
        return -1;
    else
    {
        /*h1=height(root->l);
        h2=height(root->r);
        h=max(h1,h2);
        h=h+1;*/
        return max(height(root->l),height(root->r))+1;
    }  
}

struct node * search(struct node * root,int v)
{
    if(root==NULL)
        return root;
    
    if(root->data==v)
        return root;

    if(root->data<v)
        return search(root->r,v);

    else
        return search(root->l,v);
}

struct node * delete(struct node * root,int v)
{
    if(root==NULL)
        return root;
    
    if(root->data<v)
    {
        root->r=delete(root->r,v);
        return root;
    }

    if(root->data>v)
    {
        root->l=delete(root->l,v);
        return root;
    }

    if(root->data==v)
    {
        if(root->l!=NULL && root->r!=NULL)
        {
            struct node* cur=findmin(root->r);
            root->data=cur->data;
            root->r=delete(root->r,root->data);
            return root;
        }

        if(root->l==NULL)
        {
            struct node* top=root->r;
            free(root);
            return top;
        }

        if(root->r==NULL)
        {
            struct node *top=root->l;
            free(root);
            return top;
        }
    }
}

int main()
{
    struct node *root=NULL;
    struct node *temp=NULL;
    int v,choice=0,c=0;

    printf("1.Insert\n");
    printf("2.Remove\n");
    printf("3.Display\n");
    printf("4.Maximum value\n");
    printf("5.Minimum value\n");
    printf("6.Height of the tree\n");
    printf("7.Search a value\n");
    printf("8.Exit\n");

    do
    {
        printf("Enter the options : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the value to be inserted : ");
                    scanf("%d",&v);
                    root=insert(root,v);
                    break;

            case 2: printf("Enter the value to be deleted : ");
                    scanf("%d",&v);
                    root=delete(root,v);
                    break;

            case 3: printf("1.Preorder\n");
                    printf("2.Inorder\n");
                    printf("3.Postorder\n");
                    printf("Enter your choice : ");
                    scanf("%d",&c);

                    switch(c)
                    {
                        case 1:preorder(root);
                               printf("\n");
                               break;

                        case 2:inorder(root);
                               printf("\n");
                               break;

                        case 3:postorder(root);
                               printf("\n");
                               break;

                        default: printf("Wrong choice!\n");
                    }
                    break;

            case 4: temp=getmax(root);
                    printf("The maximum value is %d\n",temp->data);
                    break;

            case 5: temp=findmin(root);
                    printf("The minimum value is %d\n",temp->data);
                    break;

            case 6: v=height(root);
                    printf("The height of the tree is %d\n",v);
                    break;

            case 7: printf("Enter the value to be searched : ");
                    scanf("%d",&v);
                    temp=search(root,v);
                    if(temp->data==v)
                        printf("The value is found\n");
                    else 
                        printf("The value is not found\n");
                    break;

            case 8: printf("Exit !\n");
                    break;

            default: printf("Wrong option !\n");
        }
    }while(choice != 8);
    return 0;
}
