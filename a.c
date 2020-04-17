#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head;
struct node *temp;
void link_list_of_integers(int n)
{
    head=(struct node*)malloc(sizeof(struct node));
    if(head == NULL)
                 {
                     printf("\n Memory not allocated ");
                     return;

                 }
    temp=head;
    int i;
    printf("\n Enter node data :");
    scanf("%d", &(head->data));
    for(i=1;i<n;i++)
    {
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
   			{
        		printf("Memory not allocated");
        		break;
    		}
    printf("\n Enter node data :");
    scanf("%d",&(newnode->data));
    temp->link=newnode;
    temp=temp->link;
    }
    temp->link=NULL;
}
void deleting_integer(int y)
{
    struct node *temp1;
    temp=head;
    while(temp->data!=y)
    {
        temp1=temp;
        temp=temp->link;
    }
    temp1->link=temp->link;
    free(temp);
}
void printing_list()
{
    temp=head;
    while(temp->link!=NULL)
    {
        printf("\ndata = %d",temp->data);
        temp=temp->link;
    }
    printf("\ndata = %d",temp->data);
}
void main()
{
   int n,y;
   printf("enter no of integers");
   scanf("%d",&n);
   link_list_of_integers(n);
   printf("enter element to be deleted");
   scanf("%d",&y);
   deleting_integer(y);
   printing_list();
}
