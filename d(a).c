#include<stdio.h>
#include<stdlib.h>
#define MAX 4
enqueue(int);
void display();
int queue_array[MAX];
int rear = 0;
int front = 0;
 enqueue(int item)
{
     rear=(rear+1)%MAX;
    if (front==rear)
    {
        printf("Queue Overflow \n");
        if(rear==0)
        {
          rear=MAX-1;
        }
        else {
        rear=rear-1;}
        return;
    }
    else
    {
    queue_array[rear]= item;
    printf("iTEM INSERTED is %d\n",queue_array[rear]);
       return;
    }
}

 deqeue()
{
    if(front==rear)
    {
         printf("Queue is empty on");
         return -1;
    }
    else
    {
          front=(front+1)%MAX;
         int item= queue_array[front];
         printf("Deleted Item is %d\n",item);
          return item;
    }

}

 main()
 {


     for (int i = front; i <= MAX-1; i++){
     enqueue(i);
      }

      for (int i = front; i <= MAX-1; i++){
       deqeue();
      }

}
