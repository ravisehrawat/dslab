#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* l;
    struct node* r;
};

void in_order(struct node* root)
{
    if(root == NULL)
    {return NULL;}
    in_order(root->l);
    printf("%d ->", root->data);
    in_order(root->r);
}
struct node* create(value)
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->l = NULL;
    newnode->r = NULL;

    return newnode;
}

struct node* insertL(struct node *root, int value) {
    root->l = create(value);
    return root->l;
}


struct node* insertR(struct node *root, int value){
    root->r = create(value);
    return root->r;
}

int main(){
    struct node* root = create(1);
    insertL(root, 34);
    insertR(root, 45);

    insertL(root->l, 589);
    insertR(root->l, 67);

    printf("in_order traversal \n");
    in_order(root);
}
