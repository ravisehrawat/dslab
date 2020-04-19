#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
int *createnode()
{
    int data;
    struct node *root= (struct node*)malloc(sizeof(struct node));
    printf("Enter the data in the root node(-1 for no data.)\n");
    scanf("%d",&data);
    if(data==-1)
   {
    printf("NO data is entered.\n");
    return NULL;
   }
    root->data=data;
    printf("Enter the left child %d\n",root->data);
    root->left=createnode();
    printf("Enter the right child %d\n",root->data);
    root->right=createnode();
}
int count(struct node *root)
    {
        if (root==NULL)
            return 0;
        else
            return ( 1 + count(root->left) + count(root->right) );
    }
void main()
{
    int x;
    struct node *root=createnode();
    x=count(root);
    printf(" no of nodes %d",x);
}
