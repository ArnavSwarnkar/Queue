#include<stdio.h>
#include<stdlib.h>
#define max 5

struct queue
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
    struct queue q;
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

void enqueue(struct queue *q,int ele)
{
    if (q->rear==max-1)
    {
        printf("Queue overflow");
    }
    else
    {
        if (q->front==-1 && q->rear==-1)
        {
            q->front++;
            q->rear++;
            q->qu[q->front]=ele;
            printf("\n%d enqueud successfully\n",ele);
        }
        else
        {
            q->rear++;
            q->qu[q->rear]=ele;
            printf("\n%d enqueud successfully\n",ele);
        }
    }
}

void dequeue(struct queue *q)
{
    if (q->front==-1 || q->front==max)
    {
        printf("\nQueue empty\n");
    }
    else
    {
        printf("\n%d dequeued\n",q->qu[q->front]);
        q->front++;
    }
}

void display(struct queue *q)
{
    if (q->front==-1 || q->front==max)
    {
        printf("\nQueue empty\n");
    }
    else
    {
        for (int i=q->front;i<=q->rear;i++)
        {
            printf("%d ",q->qu[i]);
        }
    }
}