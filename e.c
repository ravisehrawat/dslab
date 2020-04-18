#include<stdio.h>
#include<stdlib.h>
typedef struct node
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
        printf("\n%d",t->data);
        inorder(t->right);
    }
    else
        return;
}
void postorder(struct node *t)
{
    if(t)
    {
        postorder(t->left);
        postorder(t->right);
	printf("\n%d",t->data);
    }
    else
        return;
}
void preorder(struct node *t)
{
    if(t)
    {
printf("\n%d",t->data);
        preorder(t->left);
        preorder(t->right);

    }
    else
        return;
}

struct node *newnode()
{
    struct node *new;

    new=(struct node*)malloc(sizeof(struct node));
    int data;
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
    printf("\n inorder");
    inorder(root);
    printf("\n postorder");
    postorder(root);
    printf("\n preorder");
    preorder(root);

}
