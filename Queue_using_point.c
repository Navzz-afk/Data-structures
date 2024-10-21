#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void enqueue(int queue[],int* front ,int * rear,int element)
{
    if(*rear==SIZE-1){
        printf("Overflow\n");
        return;}
    if(*front==-1)
    *front=0;
    (*rear)++;
    queue[*rear]=element;
    return;
}

void dequeue(int queue[],int* front,int* rear)
{
    if(*front>(*rear) || *front==-1){
        printf("Underflow\n");
        return ;
    }
    else
        {printf("Element removed is %d\n",queue[(*front)++]);
        return ;
        }
}

void display(int queue[],int front , int rear)
{
    if(front>(rear) || front==-1)
        {printf("Underflow\n");
        return;
        }
    else
        for(int i=front;i<=rear;i++)
    {
        printf("%d  ",queue[i]);
    }
    printf("\n");
}

void main()
{
    int queue[SIZE];
    int rear=-1,front=-1;
    int ch,ele;
    while(1)
    {
        printf("Enter choice:\n 1. enqueue \n 2. dequeue \n 3. display \n 4.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter element to input\n");
                scanf("%d",&ele);
                enqueue(queue,&front,&rear,ele);
                break;
            case 2:
                dequeue(queue,&front,&rear);
                break;
            case 3:
                display(queue,front,rear);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid input\n");
        }
    }
}
