#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct
{
    int data[MAX];
    int top;
}stack;

void init(stack *s)
{
    s->top=-1;
}

void push(stack *s, char v)
{
    if(s->top == MAX-1)
        printf("Overflow !!!\n");
    else
    {
        s->top++;
        s->data[s->top] = v;
    }
}

void pop(stack *s,char *v)
{
    if(s->top == -1)
        printf("Underflow !!!\n");
    *v=s->data[s->top];
    s->top--;
}

int isempty(stack *s)
{
    if(s->top == -1)
        return 1;
    else 
        return 0;
}

int isoperand(char s)
{
    if((s>='A' && s<='Z')||(s>='a' && s<='z'))
        return 1;
    else
        return 0;  
}

int opno(char a)
{
    int k;
    switch(a)
    {
        case '+':
        case '-':k=1;
                 break;
        case '*':
        case '/':k=2;
                 break;
    }
    return k;
}

int isLHorSS(char a,char b)
{
    if(opno(a)<=opno(b))
        return 1;
    else
        return 0;
}

void display(char * arr)
{
    printf("Prefix : %s\n", arr);
}

void reverse(char * arr)
{
    int n=0;
    char temp;
    while(arr[n]!='\0')
        n++;
    for(int i=0;i<n/2;i++)
    {
        temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
}

void intopre(char * in)
{
    int i=0,j=0;
    char k;
    char out[100];
    reverse(in);
    stack s;
    init(&s);

    while(in[i]!='\0')
    {
        if(isoperand(in[i]))
            out[j++]=in[i];
        
        else if(in[i]=='(')
            push(&s,in[i]);

        else if(in[i]==')')
        {
            while(1)
            {
                pop(&s,&k);
                if(k=='(')
                    break;
                else
                    out[j++]=k;
            }
        }
        else
        {
            if(isempty(&s))
                push(&s,in[i]);
            else
            {
                pop(&s,&k);
                if(k=='('||isLHorSS(k,in[i]))
                {
                    push(&s,k);
                    push(&s,in[i]);
                }
                else
                {
                    out[j++]=k;
                    i--;
                }
            }
        }
        i++;
    }
    while(!isempty(&s))
    {
        pop(&s,&k);
        out[j++]=k;
    }
    out[j]='\0';
    reverse(out);
    display(out);
}

int main()
{
    char in[100];
    printf("Enter the infix expression : ");
    scanf("%s",in);
    intopre(in);
    return 0;
}