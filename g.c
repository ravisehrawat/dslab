#include<stdio.h>
#include<stdlib.h>

int count,n;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void inorder(struct node *t)
{
    if(t)
    {
        inorder(t->left);
        n=n+1;
        if((t->left==NULL)&&(t->right==NULL))
        {
            count=count+1;
        }

        inorder(t->right);

    }
    else
        return;
}
struct node *newnode()
{
    struct node *new;

    new=(struct node*)malloc(sizeof(struct node));
    int data;
    printf("Enter the data for the nodes ");
    scanf("%d",&data);
    if(data==0)
    {
        return NULL;
    }
    new->data=data;
    printf("enter left child of %d\n",data);
    new->left=newnode();
    printf("enter right child of %d\n",data);
    new->right=newnode();
    return new;
};
void main()
{
    struct node *root;
    root=newnode();
    inorder(root);
    printf("no of leaf nodes %d",count);
    printf("\n no of non leaf nodes %d",n-count);
}
