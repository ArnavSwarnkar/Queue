#include<stdio.h>
#include<stdlib.h>
#define max 5

struct cir_queue
{
    int rear;
    int front;
    int qu[max];
};

void enqueue();
void dequeue();
void display();

void main()
{
    struct cir_queue q;
    q.rear=-1;
    q.front=-1;
    int item,choice;
    while(1)
    {
        printf("\nWhat would you like to do?\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter element to enqueue: ");
            scanf("%d",&item);
            enqueue(&q,item);
            break;

            case 2:
            dequeue(&q);
            break;

            case 3:
            display(&q);
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("Enter valid input\n");
            break;
        }
    }
}

void enqueue(struct cir_queue *q,int ele)
{
    if (q->rear==max-1 && q->front==-1)
    {
        printf("Queue overflow");
    }
    else
    {  
            q->rear=(q->rear+1)%max;
            q->qu[q->rear]=ele;
            printf("\n%d enqueued successfully\n",ele);
    }
}

void dequeue(struct cir_queue *q)
{
    if ((q->front==-1 && q->rear==-1) || (q->front==max-1))
    {
        printf("\nQueue empty\n");
    }
    else
    {
        printf("\n%d dequeued\n",q->qu[q->front+1]);
        q->front=(q->front+1)%max;
    }
}

void display(struct cir_queue *q)
{
    if ((q->front==-1 && q->rear==-1) || (q->front==max-1))
    {
        printf("\nQueue empty\n");
    }
    else
    {
        for (int i=q->front+1;i<=q->rear;i=(i+1)%max)
        {
            printf("%d ",q->qu[i]);
        }
        printf("\nThe front element is %d",q->qu[q->front+1]);
    }
}