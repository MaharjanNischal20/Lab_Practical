//Circular Queue


#include<stdio.h>
#include<conio.h>
#define MAXSIZE 5

int front,rear,queue[20],item;
void enqueue()
{
    if(front==(rear+1)%MAXSIZE)
    {
        printf("Queue is full");
    }
    else
    {
        printf("\nEnter the item you want to enter:");
        scanf("%d",&item);
        rear=(rear+1)%MAXSIZE;
        queue[rear]=item;
    }
}
void dequeue()
{
    if(rear==front)
        {
            printf("Queueue is empty");
        } 
    else
    {
        front=(front+1)%MAXSIZE;
        item=queue[front];
    printf("\nRemoved number is: %d\n",item);
    }
}
void display()
{
    int i;
    if(rear==front)
    {
        printf("queue is empty");
    }
    else
    {
        for(i=(front+1)%MAXSIZE;i!=rear;i=(i+1)%MAXSIZE)
        {
            printf("%d\t",queue[i]);
        }
        printf("%d\t",queue[rear]);
    }
}
int main()
{
    int n;
    do
    {
    printf("Select choice \n 1.Enqueue \n 2.Dequeue \n 3.Display\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        enqueue();
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        default:
        {
            printf("Please Enter appropriate number 1,2,3....Thank You");
        }
        break;
    }
    }while(n!=0 && n<4);
    return 0;
}