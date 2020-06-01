#include<stdio.h>
#include<stdlib.h>

struct node
 {
    char data;
    struct node* left;
    struct node* right;
};
struct node *root=NULL;
struct node *decl(char key)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->right=NULL;
    temp->left=NULL;
    temp->data=key;
    return temp;
};
struct node *create(struct node* root,char key)
{
    if (root==NULL)
    return decl(key);
    if (root->data<key)
    root->right=create(root->right,key);
    if (root->data>key)
    root->left=create(root->left,key);
    return root;
}
void preorder(struct node* root)
{
    if (root==NULL)
    {
        return NULL;
    }
    printf ("%c",root->data);
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int y;
    printf ("To insert a node press 1 else press 0 to continue\n");
    scanf("%d",&y);
    while(y)
    {
        if (y==1)
        {
            char key;
            printf ("Enter data to insert\n");
            fflush(stdin);
            scanf("%c",&key);
            root=create(root,key);
        }
        printf ("To insert a node press 1 else press 0 to continue\n");
        scanf("%d",&y);
    }
    printf ("\nPreorder Traversal\n");
    preorder(root);
}

