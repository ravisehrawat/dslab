#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *previous;
};
struct node *head;
struct node *temp;
void enque()
{
    temp=head;
    while(temp->next!=head)
    {
        printf("\n  %d",temp->data);
        temp=temp->next;
    }
     printf("\n  %d",temp->data);
}

void deque()
{
    while(head!=temp)
    {
        head=head->next;
        printf("\n item deleted is %d",head->previous->data);
        free(head->previous);
    }
    printf("\n item deleted is %d",head->data);
    free(head);
    printf("\n queue is empty..all elements are deleted");
}
void main()
{
    int i;
    head=(struct node*)malloc(sizeof(struct node));
    head=0;
    for(i=1;i<=4;i++)
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&(new->data));
        if(head==0)
        {

          head=new;
          temp=new;
          head->previous=head;
          head->next=head;
        }
        else
        {
            temp->next=new;
            new->previous=temp;
            new->next=head;
            head->previous=new;
            temp=new;
        }
    }
    enque();
    deque();
}
