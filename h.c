#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode()
{
    struct node *new;

    new=(struct node*)malloc(sizeof(struct node));
    int data;
    printf("Enter the data for the node ");
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
int c(struct node *t)
{
    int l,r;
    if(!t)
        return 0;
        else if((!(t->left==NULL))&&(!(t->right==NULL)))
        {
            return 0;
        }
    else
    {
    l=c(t->left);
    r=c(t->right);
            return (1+(l>r)?l:r);
    }
}
void main()
{
    struct node *root;
    root=newnode();
    int height=c(root);
    printf("%d",height);


}
