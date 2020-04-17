#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *previous;
    int data;
    struct node *next;
};
struct node *head;
struct node *temp;
void doubly(int n)
{
    int i;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
     {
         printf("Memory not allocated");
         return;
     }
    printf("\n Enter node data : ");
    scanf("%d",&(head->data));

    head->previous=NULL;
    head->next=NULL;
    temp=head;

    for(i=1;i<n;i++)
    {
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
   			{
        		printf("Memory not allocated");
        		break;
    		}
    printf("\n Enter node data : ");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    newnode->previous=temp;
    temp->next=newnode;
    temp=temp->next;
    }

}
void deletion(int y)
{

    temp=head;
    struct node *temp1;
    while(temp->data!=y)
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=temp->next;

    free(temp);
}
void print()
{

    temp=head;
    while(temp->next!=NULL)
    {
        printf("\n data = %d",temp->data);
    temp=temp->next;
    }
    printf("\n data = %d",temp->data);
}
void main()
{
    int n,y;
    printf("enter no of nodes");
    scanf("%d",&n);
    doubly(n);
    printf("enter element to be deleted");
    scanf("%d",&y);
    deletion(y);
    print();
}
