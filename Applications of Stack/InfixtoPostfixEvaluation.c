#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct
{
    int data[MAX];
    int top;
}stack;

stack s1;

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
    if((s>='A' && s<='Z')||(s>='a' && s<='z')||s=='0'||s=='1'||s=='2'||s=='3'||s=='4'||s=='5'||s=='6'||s=='7'||s=='8'||s=='9')
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

int isltoh(char a,char b)
{
    if(opno(a)<opno(b))
        return 1;
    else
        return 0;
}

void display(char * arr)
{
    printf("Postfix : %s\n", arr);
}

void evaluate(char * exp)
{
    int n=0,val,a,b;
    char x,y;
    while(exp[n]!='\0')
        n++;
    
    for(int i=0; i<n; i++)
    {
        if(exp[i]=='0'||exp[i]=='1'||exp[i]=='2'||exp[i]=='3'||exp[i]=='4'||exp[i]=='5'||exp[i]=='6'||exp[i]=='7'||exp[i]=='8'||exp[i]=='9')
        {
            char digitval = exp[i];
            push(&s1,digitval);
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
        {
            pop(&s1,&x);
            pop(&s1,&y);
            a=(int)x%48;
            b=(int)y%48;

            switch(exp[i])
            {
                case '+':val=b+a;
                         break;
                case '-':val=b-a;
                         break;
                case '*':val=b*a;
                         break;
                case '/':val=b/a;
                         break;
            }
            push(&s1,val);
        }
    }
    pop(&s1,&x);
    a=(int)x%48;
    printf("The result of the evaluation of the expression is %d \n",x);
}

void intopost(char * in)
{
    int i=0,j=0;
    char k;
    char out[100];
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
                if(k=='('||isltoh(k,in[i]))
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
    display(out);
    evaluate(out);
}

int main()
{
    char in[100];
    printf("Enter the infix expression : ");
    scanf("%s",in);
    intopost(in);
    init(&s1);
    return 0;
}