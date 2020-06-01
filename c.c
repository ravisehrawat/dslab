#include<stdio.h>
#include<stdlib.h>
#define max_size 100
int stack[max_size];
int choice,n;
int top=-1;
/*push operation*/
void push(char data)
{
    if(top==n-1)
    {
        printf("stack is in overflow condition");
    }
    top=top+1;
    stack[top]=data;
    printf("pushed element is %c\n",data);
}
/*pop operation*/
char pop()
{
    if(top==-1)
    {
        printf("stack is in underflow condition");
    }
    printf("popped element is %c\n",stack[top]);
    top=top-1;
}
int operator(char Q)
{
    if(Q=='*'||Q=='^'||Q=='+'||Q=='-'||Q=='/')
    {
        return 1;
    }
    else
        return 0;
}
int precedence(char Q)
{
    if (Q=='^')
    {
       return 5;
    }
    else
    {
        if (Q=='*')
        {
           return 4;
        }
    else
    {
    if (Q=='/')
    {
        return 3;
    }
    else
    {
    if(Q=='+')
    {
      return 2;
    }
    else
    {
        if(Q=='-')
        {
       return 1;
    }
    else
    {
    return 0;
    }
    }
    }
    }
    }
}

void infix_to_postfix()
{
    char infix[20];
    char postfix[20];
    char ch,x;
    int i=0;
    int j=0;
    /*intizillisation*/
    ch=infix[i];
    while(ch!=NULL)
    {
        if(isalpha(ch)||isdigit(ch))
        {
            postfix[j]=ch;
            j++;
            printf("print data is %c\n",ch);
        }
        else
        {
            if(ch=='(')
            {
                push(ch);
            }
            else
            {
                if(ch==')')
                {
                    x=pop();
                    while(x!='(')
                    {
                        postfix[j]=x;
                        j++;
                        x=pop();
                    }
                }
                else
                {
                    if(operator(ch)==1)
                    {
                        x=pop();
                        while(operator(x)==1&&precedence(x)>precedence(ch))
                        {
                            postfix[j]=x;
                            j++;
                            printf("%c\n",x);
                            x=pop();
                        }
                        push(x);
                        push(ch);
                    }
                }
            }
        }
        i++;
        ch=infix[i];
    }
    while(top!=-1)
    {
        printf("%c",stack[top--]);
    }
}
void main()
{
    printf("enter the size of stack\n");
    scanf("%d",&n);
    char ravi[20];
    char sehrawat[20];
    printf("enter the infix expression\n");
    scanf("%s",ravi[20]);
    infix_to_postfix();
    printf("postfix expression is\n");
    scanf("%s",sehrawat[20]);
}
